#pragma once

#include "Stream.h"

#include "msgpack.hpp"

namespace ofxMessagePack {
	class Packer : public Stream {
	public:
		Packer();
		
		template<typename T>
		Packer & operator<<(T & object) {
			this->packer.pack(object);
			return * this;
		}
		
		bool save(string filename) const;
		
		ofBuffer getBuffer() const override;
	protected:
		msgpack::sbuffer buffer;
		msgpack::packer<msgpack::sbuffer> packer;
	};
}