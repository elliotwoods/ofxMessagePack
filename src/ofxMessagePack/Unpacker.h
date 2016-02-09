#pragma once

#include "ofLog.h"
#include "Stream.h"

#include "msgpack.hpp"

namespace ofxMessagePack {
	class Unpacker : public Stream {
	public:
		Unpacker();
		
		template<typename T>
		Unpacker & operator>>(T & object) {
			if (this->hasMessageReady) {
				this->message.get().convert(& object);
				this->moveToNextMessage();
			} else {
				ofLogError("ofxMessagePack::Unpacker") << "Cannot unpack message, no message left in buffer";
			}
			return *this;
		}
		
		operator bool() {
			return this->isMessageReady();
		}
		
		bool load(string filename);
		bool isMessageReady() const;
		
		ofBuffer getBuffer() const override;
		void setBuffer(const ofBuffer &);
		
		/// This is called automatically, only use this if you know what you're doing
		void moveToNextMessage();
	protected:
		msgpack::unpacker unpacker;
		msgpack::unpacked message;
		bool hasMessageReady;
	};
}