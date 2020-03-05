#include "ofApp.h"

// Track mouse with fade

ofFbo fbo;  // framebuffer object
ofColor bgcolor(51,204,204);
ofColor white(255);
ofVec2f p1,p2,p3,p4;
ofVec2f l1,l2;


bool title;

//--------------------------------------------------------------
void ofApp::setup(){
  //fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);  // lower precision. leaves artifacts. way faster.
  fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
  fbo.begin();
    ofClear(255,255,255, 0);
  fbo.end();
  ofSetBackgroundColor(bgcolor);
    koliko.load("koliko.ttf", 30, true, true);
    koliko.setLineHeight(34.0f);
    p1.set(-20, 100);
    p2.set(-30,26);
    p3.set(60,24);
    p4.set(70,129);
    l1.set(200,330);
    l2.set(l1.x+170,l1.y);
    ofSetLineWidth(5);
    ofFill();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
}

int mouseX = 0;
int mouseY = 0;

//--------------------------------------------------------------
void ofApp::draw(){
    fbo.begin();
    ofSetColor(bgcolor, 1); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    if (title) {
        ofSetColor(255);
        koliko.drawString("Nuwa Mended the Fallen", 500, 300);
        title=false;
    }
    fbo.end();
    ofTranslate(0,0);
    fbo.draw(0,0);
    
    
    if (p1.y<mouseY) {
        for (int i=1; i<=12; i++) {
            p1+=(2,3);
            p2+=(8,1);
            p3+=(12,3);
            p4+=(6,1);
            ofDrawCurve(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,p4.x,p4.y);
        }
        
    }
    else   {
        p1.set(-20, 100);
        p2.set(-30,26);
        p3.set(60,24);
        p4.set(70,129);
        
    }
    l1.set(mouseX-30, mouseY-20);
    l2.set(l1.x+220,l1.y);
    
    ofDrawLine(l1.x, l1.y, l2.x, l2.y);
        
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
      if(key=='f'){
          title=true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mouseX = x;
    mouseY = y;
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

void ofApp::mycurve(float m, float n,float q,float p, float a, float b, float c,float d){
    
    
}
