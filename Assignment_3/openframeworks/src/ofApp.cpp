#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("title");

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int x =ofGetFrameNum()/120%5;
    int nR;// number of rectangle
    int nC;//number of circles
    cout<<x<<endl;
    // center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    // line
    ofSetColor(255, 0, 0);
    ofSetLineWidth(3);
    ofNoFill();
    switch (x) {
        //element 1
        case 4:
            nR=5;
            for (int i=1; i<=nR; i++) {
                ofDrawRectangle(0, 0,i*20,i*20);
            }
            break;
        //element 2
        case 1:
            nC=5;
            for (int i=0; i<=nC; i++) {
                int r=20*(nC+1-i);
                ofDrawCircle(0-r, 0, r);
            }
            break;
        //element 3
        case 2:
            nR=10;
            for (int i=1; i<=nR; i++) {
                ofDrawRectangle(0, 0,i*20,i*20);
            }
            break;
        //element 4
        case 3:
            nC=10;
            for (int i=0; i<=nC; i++) {
                int r=20*(nC+1-i);
                ofDrawCircle(0-r, 0, r);
            }
           
            break;
        //Face
        case 0:
            //FACE
            ofDrawCircle(0, 0, 100);
            ofSetRectMode(OF_RECTMODE_CENTER);
            //EYES
            ofDrawRectangle(-30, -30,30,40);
            ofDrawRectangle(30, -30,30,40);
            //MOUTH
            ofDrawLine(-20, 20, 10, 10);
            ofSetRectMode(OF_RECTMODE_CORNER);
            break;
            
        default:
            break;
    }
        
        
    }


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
