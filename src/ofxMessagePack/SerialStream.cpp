#include "SerialStream.h"

namespace ofxMessagePack {
	//----------
	SerialStream::SerialStream(std::shared_ptr<ofSerial> serial)
		: serial(serial)
	{
	}

	//----------
	void
		SerialStream::write(const char* buffer, size_t length)
	{
		this->serial->writeBytes(buffer, length);
	}

	//----------
	void
		SerialStream::read()
	{
		// Find how much data is available
		auto available = this->serial->available();

		// Calculate our new buffer size
		const auto priorSize = this->buffer.size();
		const auto newSize = priorSize + available;

		// Check if we exceed max buffer size
		if (newSize > this->maxSize) {
			return;
		}

		// Allocate buffer
		this->buffer.resize(newSize);

		// Read into buffer
		auto bytesRead = this->serial->readBytes(this->buffer.data() + priorSize, available);

		// Trim the buffer if necessary
		if (bytesRead != available) {
			this->buffer.resize(priorSize + bytesRead);
		}
	}

	//----------
	char*
		SerialStream::data()
	{
		return (char *) this->buffer.data();
	}

	//----------
	const char*
		SerialStream::data() const
	{
		return const_cast<char*>((char *) this->buffer.data());
	}

	//----------
	size_t
		SerialStream::size() const
	{
		return this->buffer.size();
	}

}