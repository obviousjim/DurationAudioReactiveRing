#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    
    duration.setup(12345);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    float innerRadius = duration.getValueForTrack("/inner", 50);
    float outerMultiplier = duration.getValueForTrack("/outer", 400);
    ofColor topColor = duration.getColorForTrack("/top", ofColor(255));
    ofColor bottomColor = duration.getColorForTrack("/bottom", ofColor(255));
    ofSetLineWidth(4);
    if(duration.hasTrack("/audio")){
        vector<float>& audio = duration.getFFTForTrack("/audio");
        int numBins = audio.size();     

        ofVec3f center = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0);
        for(int i = 0; i < numBins; i+=4){

            float angle = ofMap(i,0,numBins-1,0, 180);
            ofVec3f leftDir = ofVec3f(0,-1,0).getRotated(angle, ofVec3f(0,0,1));
            ofVec3f rightDir = ofVec3f(0,-1,0).getRotated(-angle, ofVec3f(0,0,1));
            ofVec3f leftPoint = (outerMultiplier*audio[i] + innerRadius ) * leftDir + center;
            ofVec3f rightPoint = (outerMultiplier*audio[i] + innerRadius ) * rightDir + center;
            ofColor lerped = topColor.getLerped(bottomColor, 1. * i / numBins);
            lerped.a = ofMap(audio[i], 0, .005, 0, 255);
            ofSetColor(lerped);
            ofLine(center + leftDir*innerRadius, leftPoint);
            ofLine(center + rightDir*innerRadius, rightPoint);
            
        }
    }
    

    duration.draw(0, 0, 200, ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}