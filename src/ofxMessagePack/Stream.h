#pragma once

#include "ofFileUtils.h"

namespace ofxMessagePack {
	class Stream {
	public:
		virtual ofBuffer getBuffer() const = 0;
	};
}
