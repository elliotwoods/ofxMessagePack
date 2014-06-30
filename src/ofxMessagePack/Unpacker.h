#pragma once

#include "Stream.h"

#include "msgpack.hpp"

namespace ofxMessagePack {
	class Unpacker : public Stream {
	public:
		Unpacker();
		
		template<typename T>
		Unpacker & operator>>(T & object) {
			if (this->hasObjectReady) {
				this->message.get().convert(& object);
				this->moveToNextMessage();
			}
		}
		
		bool operator()() {
			return this->hasObjectReady;
		}
		
		bool load(string filename);
		
		ofBuffer getBuffer() const override;
		void setBuffer(const ofBuffer &);
		
		/// This is called automatically, only use this if you know what you're doing
		void moveToNextMessage();
	protected:
		msgpack::unpacker unpacker;
		msgpack::unpacked message;
		bool hasObjectReady;
	};
}