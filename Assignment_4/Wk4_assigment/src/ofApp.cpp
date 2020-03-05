#include "ofApp.h"


//Speed
float s=0.1f;
//point1,2
ofVec2f g1,f1,m1,m2,m3,m4;
ofVec2f eye,eyebrow;
ofVec2f eb1,eb2,eb3,eb4;



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetWindowTitle("Week4Assignment");
    // line
    ofSetColor(255);
    ofSetLineWidth(3);
    ofNoFill();
    ofSetCircleResolution(50);
    //Center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //Face
    //ofDrawCircle(0, 0, 100);
    //Eyes
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(-30, -30,30,40);
    ofDrawRectangle(30, -30,30,40);
    //mouth
    ofDrawLine(-20, 20, 10, 10);
    ofSetRectMode(OF_RECTMODE_CORNER);
    
    //set point
    g1.set(-30,-30);
    eye.set(50,-20);
    eyebrow.set(40,-90);
    
    m1.set(-70,120);//70,20
    m2.set(-50,120);//50,85
    //sad x:-60,-50,40,50 y:30,25,10,20
    m3.set(50,85);
    m4.set(70,20);
    
    //eyebrow
    eb1.set(40,-90);
    eb2.set(35,-95);
    eb3.set(25,-95);
    eb4.set(20,-90);
    
    f1.set(80,-40);
    
    
   
    
    



}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int x =ofGetFrameNum()/60%12;
    //cout<<x<<endl;
    ofSetColor(255);
    ofSetLineWidth(3);
    ofNoFill();
    ofSetCircleResolution(50);
    //Center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //Face
    ofDrawCircle(0, 0, 100);
        switch (x) {
        //happiness
        //--------------------------------------------------------------
        case 0:
            //Move eye
            seteyes(30, -5);
            eyes();
            //Move eyebrow
            setXEyebrows(40, 35, 25, 20);
            setYEyebrows(-50, -55, -55, -50);
            eyebrows();
            //mouth ofDrawBezier(-70, 20, -50, 85, 50, 85, 70, 20);
            m1.x+=s*(-70-m1.x);
            m2.x+=s*(-70-m2.x);
            m1.y+=s*(20-m1.y);
            m2.y+=s*(85-m2.y);
            mouth();
            break;
        case 1:
            happiness();
            break;
        case 2:
            happiness();
            break;
        //sad
        //--------------------------------------------------------------
        case 3:
            //mouth
            //sad x:-60,-50,40,50 y:30,25,10,20
            setXMouth(-60, -50, 40, 50);
            setYMouth(30,25, 10, 20);
            //eyes
            eye.x+=s*(40-eye.x);
            eye.y+=s*(-10-eye.y);
            //eyebrow
            //x:80,75,50,20
            //y:-10,-13,-15,-40
            setXEyebrows(80, 75, 50, 20);
            setYEyebrows(-10, -13, -15, -40);
            
            eyes();
            eyebrows();
            mouth2();
            break;
        case 4:
            sad();
            break;
        case 5:
            sad();
            break;
        //surprised
        //--------------------------------------------------------------
        case 6:
            //eyes
            seteyes(45, -10);
            f1.x+=s*(45-f1.x);
            f1.y+=s*(-10-f1.y);
            
            eyes();
            ofDrawCircle(f1.x, f1.y, 30);
            ofDrawCircle(f1.x*-1, f1.y, 30);
            //mouth
            setXMouth(-30, -10, 10 , 20);
            setYMouth(55, 50, 45, 40);
            mouth2();
            break;
        case 7:
            surprise();
            break;
        case 8:
            surprise();
            
            break;
        //anger
        //--------------------------------------------------------------
        case 9:
            //eye
            seteyes(35, 0);
            eyes();
            //eyebrow
            setXEyebrows(80, 60, 40, 20);
            setYEyebrows(-40, -35, -30, -10);
            eyebrows();
            //
            setXMouth(-15,-5, 5, 15);
            setYMouth(45, 20, 20, 45);
            mouth2();
            break;
        case 10:
            anger();
            break;
        case 11:
            anger();
            break;
        //
        //--------------------------------------------------------------
            
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
void ofApp::happiness(){
    //eyes
    eyes();
    eyebrows();
    mouth();
}
void ofApp::sad(){
    eyes();
    eyebrows();
    mouth2();
}
void ofApp::surprise(){
    eyes();
    ofDrawCircle(f1.x, f1.y, 30);
    ofDrawCircle(f1.x*-1, f1.y, 30);
    mouth2();
}
void ofApp::anger(){
    eyes();
    eyebrows();
    mouth2();
}

void ofApp::mouth(){
    ofDrawBezier(m1.x,m1.y,m2.x,m2.y,m2.x*-1,m2.y,m1.x*-1,m1.y);
}

void ofApp::mouth2(){
    ofDrawBezier(m1.x,m1.y,m2.x,m2.y,m3.x,m3.y,m4.x,m4.y);
}
void ofApp::eyebrows(){
    ofDrawBezier(eb1.x,eb1.y,eb2.x,eb2.y,eb3.x,eb3.y,eb4.x,eb4.y);
    ofDrawBezier(eb1.x*-1,eb1.y,eb2.x*-1,eb2.y,eb3.x*-1,eb3.y,eb4.x*-1,eb4.y);
}
void ofApp::setXEyebrows(int m,int n,int p, int q){
    eb1.x+=s*(m-eb1.x);
    eb2.x+=s*(n-eb2.x);
    eb3.x+=s*(p-eb3.x);
    eb4.x+=s*(q-eb4.x);
}

void ofApp::setYEyebrows(int m,int n,int p, int q){
    eb1.y+=s*(m-eb1.y);
    eb2.y+=s*(n-eb2.y);
    eb3.y+=s*(p-eb3.y);
    eb4.y+=s*(q-eb4.y);
    
}
void ofApp::setXMouth(int m,int n,int p, int q){
    
    m1.x+=s*(m-m1.x);
    m2.x+=s*(n-m2.x);
    m3.x+=s*(p-m3.x);
    m4.x+=s*(q-m4.x);
}
void ofApp::setYMouth(int m,int n,int p, int q){
    m1.y+=s*(m-m1.y);
    m2.y+=s*(n-m2.y);
    m3.y+=s*(p-m3.y);
    m4.y+=s*(q-m4.y);
}
void ofApp::seteyes(int m, int n){
    eye.x+=s*(m-eye.x);
    eye.y+=s*(n-eye.y);
}
void ofApp::eyes(){
    ofFill();
    ofDrawEllipse(eye.x, eye.y, 8, 11);
    ofDrawEllipse(eye.x*-1, eye.y, 8, 11);
    ofNoFill();
}




