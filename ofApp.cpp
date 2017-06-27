#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	//ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setRadius(300);	
	this->icoSphere.setResolution(5);

	this->triangles = icoSphere.getMesh().getUniqueFaces();

	this->light.setAreaLight(2048, 2048);
	this->light.setAmbientColor(ofFloatColor(0.0, 0.0, 0.0, 1.0));
	this->light.setDiffuseColor(ofFloatColor(1.0, 1.0, 1.0));
	this->light.setSpecularColor(ofFloatColor(1.0, 0.0, 0.0));
}

//--------------------------------------------------------------
void ofApp::update(){
	this->light.setPosition(this->cam.getPosition().normalize() * 2048);
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofEnableLighting();
	this->light.enable();

	cam.begin();

	//ofRotateY(ofGetFrameNum() % 360);

	float noise_value;
	vector<ofMeshFace> tmp_triangles = this->triangles;

	ofColor c = ofColor(255);
	for (int i = 0; i < triangles.size(); i++) {

		for (int j = 0; j < 3; j++) {
			noise_value = ofNoise(triangles[i].getVertex(j).x * 0.5, triangles[i].getVertex(j).y * 0.5, triangles[i].getVertex(j).z * 0.5, ofGetFrameNum() * 0.01);

			if (noise_value < 0.6) {
				c = ofColor(0, 0, 255);
			}
			else {
				c = ofColor(255);
			}

			tmp_triangles[i].setVertex(j, triangles[i].getVertex(j).normalized() * 400 * noise_value);
			tmp_triangles[i].setColor(j, c);
		}
	}

	this->icoSphere.getMesh().setFromTriangles(tmp_triangles);

	//this->icoSphere.draw();
	this->icoSphere.drawWireframe();

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
