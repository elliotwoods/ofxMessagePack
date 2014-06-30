#include "Packer.h"
#include "ofUtils.h"

namespace ofxMessagePack {
	//----------
	Packer::Packer() : packer(buffer) {
		
	}
	
	//----------
	bool Packer::save(string filename) const {
		ofstream file;
		file.open(ofToDataPath(filename).c_str(), ios::out | ios::binary);
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