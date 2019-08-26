#include "Packer.h"
#include "ofUtils.h"
#include "ofLog.h"

namespace ofxMessagePack {
	//----------
	Packer::Packer() : packer(buffer) {
		
	}
	
	//----------
    bool Packer::save(std::string filename) const {
		std::ofstream file;
		file.open(ofToDataPath(filename).c_str(), std::ios::out | std::ios::binary);
		try {
			if (file.fail()) {
				return false;
			}
			file.write(buffer.data(), buffer.size());
			file.close();
			return true;
		} catch (std::exception & e) {
			ofLogError("ofxMessagePack") << "Failed to save to file \"" << filename << " : " << e.what();
			file.close();
			return false;
		}
	}
	
	//----------
	ofBuffer Packer::getBuffer() const {
		ofBuffer buffer;
		buffer.set(this->buffer.data(), this->buffer.size());
		return buffer;
	}
}
