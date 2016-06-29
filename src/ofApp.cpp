#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addDepthGenerator();
    kinect.addUserGenerator();
    
    kinect.start();
    mode = false;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    kinect.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(!mode){
        ofSetColor(255, 0, 0);
        ofDrawCircle(50,50, 10);
    }else{
        ofSetColor(0, 255, 0);
        ofDrawCircle(50, 50, 10);
    }
    
    
    ofPushMatrix();
    ofTranslate(200, 50, - 100);
    
    if(kinect.getNumTrackedUsers() > 0 ){
        
        ofxOpenNIUser user = kinect.getTrackedUser(0);
        
        ofSetColor(255);
        
        for(int i = 0; i < user.getNumLimbs(); i ++){
            
            ofxOpenNILimb limb = user.getLimb((enum Limb) i);
            
            if( limb.isFound()){
                
                float x1 = limb.getStartJoint().getProjectivePosition().x;
                float y1 = limb.getStartJoint().getProjectivePosition().y;
                float x2 = limb.getEndJoint().getProjectivePosition().x;
                float y2 = limb.getEndJoint().getProjectivePosition().y;
                ofDrawLine(x1, y1, x2, y2);
                
            }
        }
        
        ofVec2f pos;
        
        for( int i = 0 ; i < user.getNumJoints(); i ++){
            
            ofxOpenNIJoint joint = user.getJoint((enum Joint)i);
            
            if(joint.isFound()){
                
                mode = true;
                ofSetColor(0, 255, 0, 100  );
                float x = joint.getProjectivePosition().x;
                float y = joint.getProjectivePosition().y;
                
                pos.set(x, y);
                ofDrawCircle(pos.x, pos.y, 10);
                
            }else{
                mode = false;
            }
        }
        
    }
    ofPopMatrix();
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
