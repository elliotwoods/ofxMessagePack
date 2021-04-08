#include "Unpacker.h"

#include "ofUtils.h"

using namespace std;

namespace ofxMessagePack {
	//----------
	Unpacker::Unpacker() {
		this->hasMessageReady = false;
	}
		
	//----------
	bool Unpacker::load(string filename) {
		ifstream file;
		file.open(ofToDataPath(filename).c_str(), ios::in | ios::binary);
		try {
			if (file.fail()) {
				return false;
			}
			ofBuffer buffer(file);
			file.close();
			this->setBuffer(buffer);
			return true;
		} catch (std::exception & e) {
			ofLogError("ofxMessagePack") << "Failed to save to file \"" << filename << " : " << e.what();
			file.close();
			return false;
		}
	}

	//----------
	bool Unpacker::isMessageReady() const {
		return this->hasMessageReady;
	}
	
	//----------
	ofBuffer Unpacker::getBuffer() const {
		ofBuffer buffer;
		
		//msgpack-c should have both const and non-const accessors
		auto & constUnpacker = const_cast<msgpack::unpacker &>(this->unpacker);
		
		buffer.set(constUnpacker.buffer(), this->unpacker.buffer_capacity());

		return buffer;
	}
	
	//----------
	void Unpacker::setBuffer(const ofBuffer & buffer) {
		this->unpacker.reserve_buffer(buffer.size());
		memcpy(unpacker.buffer(), buffer.getData(), buffer.size());
		this->unpacker.buffer_consumed(buffer.size());
		this->moveToNextMessage();
	}
	
	//----------
	void Unpacker::moveToNextMessage() {
		if (this->unpacker.next(this->message)) {
			this->hasMessageReady = true;
		} else {
			this->hasMessageReady = false;
		}
	}
}
