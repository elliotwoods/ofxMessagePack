#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(40, 10);
	
	ofDrawBitmapStringHighlight("Draw with your mouse cursor. Press [s] to save. [l] to load. [c] to clear.", 10, 20);
	
	for(auto point : this->points) {
		ofPushStyle();
		ofColor color(200, 100, 100);
		color.setHue(fmod(point.first * 30.0f, 255.0f));
		ofSetColor(color);
		ofDrawCircle(point.second, 10.0f);
		ofPopStyle();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		ofxMessagePack::Packer packer;
		packer << this->points;
		packer.save("points.bin");
	}
	
	if (key == 'l') {
		this->points.clear();
		
		ofxMessagePack::Unpacker unpacker;
		unpacker.load("points.bin");
		unpacker >> this->points;
	}
	
	if (key == 'c') {
		this->points.clear();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//do the smae thing as when pressed
	this->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	MyPoint newPoint;
	newPoint.x = ofGetMouseX();
	newPoint.y = ofGetMouseY();
	this->points[ofGetElapsedTimef()] = newPoint;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
