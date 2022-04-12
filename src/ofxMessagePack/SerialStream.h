#pragma once

#include "ofSerial.h"
#include <memory>
#include <deque>

namespace ofxMessagePack {
	class SerialStream {
	public:
		SerialStream(std::shared_ptr<ofSerial>);

		// Write functions
		void write(const char* buffer, size_t length);

		// Read functions
		void read();
		char* data();
		const char* data() const;
		size_t size() const;
	protected:
		const size_t maxSize = 100 * 1024 * 1024;
		std::shared_ptr<ofSerial> serial;
		std::vector<uint8_t> buffer;
	};
}