#include "ofApp.h"
#include<stdlib.h>
#include<time.h>
//Project1
//Nuwa Mended the Falled
ofColor white(255,255,255),black(0,0,0),water(36,93,192),fire(223,88,100);
ofFbo fbo;
//ofVec2f
//nw: nvwa nwa: nvwa's afterimage
ofVec2f nw,nwa;
//god of Water and god of Fire
ofVec2f gW,gF;
float size=40;
// cppl: create people (C2) 0=target
ofVec2f n1,n2,cPpl0,cPpl1;
ofVec2f ppl[64],ppl2[64],ppl3[64],ppl4[64],cppl[2];
ofFbo fbo1;
float dis=-1000;
//bool
bool rr=true;
bool back;
bool tri[20];
int tran[9];
int cue=0;
int frame[20];
//int frame0,frame1,frame2;
int c2Click;

float s=0.3f;
float sRandom[64];
//width height of window
//nww: width of the nvwa square
//nwaw: width od the afterimage of nvwa
float width,height,nww,nwaw,r1,mX,mY;
ofPolyline polyline1;

//c6
float length,Move;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetWindowTitle("Project1");
    ofBackground(black);
    ofSetRectMode(OF_RECTMODE_CENTER);
    //fbo
    fbo1.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo1.begin();
        ofClear(255,255,255, 0);
    fbo1.end();
    width=ofGetWidth();
    height=ofGetHeight();
    
    //ramdon
    srand((unsigned)time(0));
    //Nuwa
    nww=20;
    //god of Water and gold of Fire
    gW.set(width/5,0);
    gF.set(width/5, height);

    //vec2
    
    n1.set(ofGetWidth()/5, ofGetHeight()/2);
    nw.set(n1.x,n1.y);
    
    //transparancy
    for (int i=0; i<=8; i++) {
        tran[i]=10*(2+rand()%9);
    }
    for (int i=0;i<8;i++){
        for (int n=0; n<8; n++) {
            ppl[n*8+i].set(width/8*i+width/16+rand()%80-40, height/8*n+height/16+rand()%80-40);
            int l=1+rand()%10;
            sRandom[n*8+i]=(1+rand()%3)*5; ppl2[n*8+i].set(ppl[n*8+i].x-width/5*l,ppl[n*8+i].y-height/5*l);
            //ppl3[n*8+i].set(ppl[n*8+i].x-width/5*l,ppl[n*8+i].y-height/5*l);
            //cout<<n*8+i<<" "<<width/8*(i+1)<<" "<<height/8*(n+1)<<endl;
        }
    }
    
    fbo.allocate(width,height,GL_RGBA32F);
    fbo.begin();
      ofClear(255,255,255, 0);
    fbo.end();
    koliko.load("koliko.ttf", 30, true, true);
    koliko.setLineHeight(34.0f);
    text.load("koliko.ttf", 15, true, true);
    text.setLineHeight(24.0f);
}
    

    


//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int x=ofGetFrameNum()/60%15;
    width=ofGetWidth();
    height=ofGetHeight();
    ofSetColor(white);
    

//    ofPath curve;
//    ofPoint p(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
//    curve.arc(p, 300, 300, 0, 360);
//    curve.arcNegative(p, 299.5, 299.5, 360, 0);
//    curve.setArcResolution(60);
//    curve.draw();
    //Draw nvwa
    if(ofGetFrameNum()/240%2==0&&cue<2){
        cue=0;
        rr=true;
    }
    if(cue==0){
        MoveNw(width/10*4,height/2);
        nwa=n1;
        DrawNwa(width/10*4,0, true);
        koliko.drawString("Nuwa Mended the Fallen", 550, 300);
        text.drawString("This is one of many Chinese flood myths ", 550, 360);
        text.drawString("that reflect the tortuous course of prehistory China.", 550, 400);
        //This is one of many Chinese flood myths that reflect the tortuous course of prehistory China.
    }
    else if (cue==1){
        MoveNw(width/5, height/2);
        koliko.drawString("Nuwa Mended the Fallen", 550, 300);
        text.drawString("This is one of many Chinese flood myths ", 550, 360);
        text.drawString("that reflect the tortuous course of prehistory China.", 550, 400);
    }
    else if(cue==2){
        MoveNw(mX, mY);
        creatPeople(mX, mY);
        for (int i=0; i<=2; i++) {
            ofDrawRectangle(cppl[i], 5, 5);
        }
        text.drawString("It was a lonely world. ", 550, 320);
        text.drawString("Nv Wa made men by moulding yellow clay.", 550, 360);
        text.drawString("She got tired but excited.", 550, 400);
        
        //she got tired. Then she conveniently drawn a
        //cane, dipped it into mud and kept slapping the cane on the ground.
    }
    else if (cue==3){
        MoveNw(mX, mY);
        drawPeople();
        text.drawString("She conveniently drawn a cane,", 550, 320);
        text.drawString("dipped it into mud", 550, 360);
        text.drawString("and kept slapping the cane on the ground.", 550, 400);
    }
    else if (cue==4){
        MoveNw(mX, mY);
        drawPeople();
        text.drawString("Mud splashed on the ground.", 550, 340);
        text.drawString("And all this spot became live human.", 550, 380);
        
    }
    else if( cue==5){
        MoveNw(mX, mY);
        drawPeople();
        text.drawString("This was the beginning of humans.", 550, 380);
        //Mud splashed on the ground
    }
    else if(cue==6){
        MoveNw(mX,mY);
        Escape();
        
    }
    else if(cue==7){
        MoveNw(mX,mY);
        Meet();
        ofSetColor(white);
        text.drawString("The fight of gods resulted in the disasters of the people.", 500, 340);
        text.drawString("Nuwa, the creator of man, would not allow this to continue.", 500, 380);
    }
    else if(cue==8){
        if(back){
        MoveNw(mX,mY);
        }
        fight2();
        if(nw.x<width/6){
            cue=9;
        }
        text.drawString("She collected rocks, melted them ", 550, 320);
        text.drawString("and used the thick liquid to mend the holes.",550,360);
        //
    }
    else if (cue==9){
        MoveNw(mX,mY);
        
        text.drawString("The skey was back in its place.", 550, 380);
        text.drawString("The rains stopped.", 550, 420);
        text.drawString("Nuwa died of exhaustion,",550,460);
        text.drawString("quite content with what she had done to her offspring.",550,500);
    }
        
    
    
    
    
    
    //circle
    
    
    
    
    
    
    

    
    
    
}

//--------------------------------------------------------------
void ofApp::MoveNw(float m, float n){
    
    nw.x+=s*(m-nw.x);
    nw.y+=s*(n-nw.y);
    ofDrawRectangle(nw, nww,nww);
    
}
//bWH: true=move horizontal false=move vertical
void ofApp::DrawNwa(float m, float n,bool bWH){
    if (bWH) {
        nwaw+=s*(m-(nwaw+nwa.x));
        if ((nwa.x+nwaw)<(m-0.5f)) {
            ofDrawRectangle(nwa, nwaw, nww);
        }
        else{
            //cout<<r1<<endl;
            s1();
        }
    }
}
void ofApp::drawPeople(){
    if (cue==3) {
        for (int i=0;i<8;i++){
            for (int n=0; n<8; n++) {
                int m=n*8+i;
                
                
                ofSetLineWidth(2);
                if(ppl2[m].x<ppl[m].x-width/20-0.1f){
                      ppl2[m].x+=s*(ppl[m].x-width/32-ppl2[m].x)/sRandom[m];
                      ppl2[m].y+=s*(ppl[m].y-height/32-ppl2[m].y)/sRandom[m];
                    ofDrawLine(ppl2[m].x,ppl2[m].y,ppl2[m].x+width/32,ppl2[m].y+height/32);
                }
                else if(ppl2[m].x<ppl[m].x-0.1f){
                    ppl2[m].x+=s*(ppl[m].x-ppl2[m].x)/sRandom[m]*2;
                    ppl2[m].y+=s*(ppl[m].y-ppl2[m].y)/sRandom[m]*2;
                    ofDrawLine(ppl2[m].x,ppl2[m].y,ppl[m].x,ppl[m].y);
                    ofDrawRectangle(ppl[m],sRandom[m]/5,sRandom[m]/5);
                }
                else if(ppl2[m].x>ppl[m].x-0.2f){
                    ofDrawRectangle(ppl2[m],sRandom[m]/5,sRandom[m]/5);
                    
                    if ((ofGetFrameNum()-frame[2])/60%6==5) {
                        tri[3]=true;
                    }
                }
            }
        }
    }
    else if(cue==4){
        
        for (int i=0;i<8;i++){
            for (int n=0; n<8; n++) {
                int m=n*8+i;
                ofDrawRectangle(ppl2[m],sRandom[m]/5,sRandom[m]/5);
                
                ofSetLineWidth(2);
                if(ppl3[m].x<ppl[m].x-width/20-0.1f){
                      ppl3[m].x+=s*(ppl[m].x-width/32-ppl3[m].x)/sRandom[m];
                      ppl3[m].y+=s*(ppl[m].y-height/32-ppl3[m].y)/sRandom[m];
                    ofDrawLine(ppl3[m].x,ppl3[m].y,ppl3[m].x+width/32,ppl3[m].y+height/32);
                }
                else if(ppl3[m].x<ppl[m].x-0.1f){
                    ppl3[m].x+=s*(ppl[m].x-ppl3[m].x)/sRandom[m]*2;
                    ppl3[m].y+=s*(ppl[m].y-ppl3[m].y)/sRandom[m]*2;
                    ofDrawLine(ppl3[m].x,ppl3[m].y,ppl[m].x,ppl[m].y);
                    ofDrawRectangle(ppl[m],sRandom[m]/5,sRandom[m]/5);
                }
                else if(ppl3[m].x>ppl[m].x-0.2f){
                    ofDrawRectangle(ppl3[m],sRandom[m]/5,sRandom[m]/5);
                    if ((ofGetFrameNum()-frame[3])/60%6==5) {
                        tri[4]=true;
                    }
                    
                }
            }
        }
    }
    
    else if(cue==5){
        
        for (int i=0;i<8;i++){
            for (int n=0; n<8; n++) {
                int m=n*8+i;
                ofDrawRectangle(ppl3[m],sRandom[m]/5,sRandom[m]/5);
                ofDrawRectangle(ppl2[m],sRandom[m]/5,sRandom[m]/5);
                ofSetLineWidth(2);
                if(ppl4[m].x<ppl[m].x-width/20-0.1f){
                      ppl4[m].x+=s*(ppl[m].x-width/32-ppl4[m].x)/sRandom[m];
                      ppl4[m].y+=s*(ppl[m].y-height/32-ppl4[m].y)/sRandom[m];
                    ofDrawLine(ppl4[m].x,ppl4[m].y,ppl4[m].x+width/32,ppl4[m].y+height/32);
                }
                else if(ppl4[m].x<ppl[m].x-0.1f){
                    ppl4[m].x+=s*(ppl[m].x-ppl4[m].x)/sRandom[m]*2;
                    ppl4[m].y+=s*(ppl[m].y-ppl4[m].y)/sRandom[m]*2;
                    ofDrawLine(ppl4[m].x,ppl4[m].y,ppl[m].x,ppl[m].y);
                    ofDrawRectangle(ppl[m],sRandom[m]/5,sRandom[m]/5);
                }
                else if(ppl4[m].x>ppl[m].x-0.2f){
                    ofDrawRectangle(ppl4[m],sRandom[m]/5,sRandom[m]/5);
                    if ((ofGetFrameNum()-frame[4])/60%6==5) {
                        tri[5]=true;
                    }
                    
                }
            }
        }
    }
    
    
}

void ofApp::creatPeople(int x, int y){
    
    
    ofSetLineWidth(8);
    if (cPpl1.x<cPpl0.x-15-0.2f){
        cPpl1.x+=s*(cPpl0.x-15-cPpl1.x);
        //ofDrawLine(cPpl1.x,cPpl1.y,cPpl1.x+8,cPpl1.y);
        //ofDrawRectangle(cPpl0, 5, 5);
    }
    else if (cPpl1.x>cPpl0.x-15-0.2f){
        cPpl1.x+=s*(cPpl0.x-cPpl1.x)/10;
        ofDrawLine(cPpl1.x,cPpl1.y,cPpl0.x,cPpl1.y);
        //ofDrawRectangle(cPpl0, 8, 8);
        
    }
}

void ofApp::Escape(){
    
    
    length+=s*(12-length);
    Move+=s*(800-Move)/10;
    for (int i=0;i<8;i++){
        for (int n=0; n<8; n++) {
            int m=n*8+i;
                
                ofDrawRectangle(ppl4[m].x+Move,ppl4[m].y,length,sRandom[m]/5);
                ofDrawRectangle(ppl3[m].x+Move,ppl3[m].y,length,sRandom[m]/5);
                ofDrawRectangle(ppl2[m].x+Move,ppl2[m].y,length,sRandom[m]/5);
            if(Move>800-0.1f){
                tri[6]=true;
                
            }
        }
    }
}
void ofApp::Meet(){
    //people
    
    for (int i=0;i<8;i++){
        for (int n=0; n<8; n++) {
        int m=n*8+i;
            ofDrawRectangle(ppl4[m].x+Move,ppl4[m].y,length,sRandom[m]/5);
            ofDrawRectangle(ppl3[m].x+Move,ppl3[m].y,length,sRandom[m]/5);
            ofDrawRectangle(ppl2[m].x+Move,ppl2[m].y,length,sRandom[m]/5);
        }
    }
    //gw and gf are fighting
//    fbo.begin();
    fight();
    
//    ofSetColor(black,10);
//    ofDrawRectangle(width/2, height/2, width, height);
//    fbo.end();
//    fbo.draw(0,0);
//
    
}

void ofApp::fight(){
        //gw and gf are fighting
    //    fbo.begin();
    size+=(120-size)*s/8;
    int frameFight;
    bool meets;
    if(gW.y<height/2-size-0.1f){
        gW.y+=s*(height/2-size-gW.y)/3;
        gF.y+=s*(height/2+size-gF.y)/3;
        //cout<<height/2-gW.y<<endl;
        
    }
    else if (gW.y>height/2-size-0.2f){
        meets=true;
        if (meets) {
            frameFight=ofGetFrameNum();
        }
        gW.y+=s*(height/2-1200-gW.y)/2;
        gF.y+=s*(height/2+1200-gF.y)/2;
        cout<<height/2-gW.y<<endl;
    }
    if((ofGetFrameNum()-frameFight)/60%6==3){
        cue=8;
    }
        ofSetColor(fire);
        ofDrawCircle(gF, size);
        ofSetColor(water);
        ofDrawCircle(gW, size);
        
    
    //    ofSetColor(black,10);
    //    ofDrawRectangle(width/2, height/2, width, height);
    //    fbo.end();
    //    fbo.draw(0,0);
    //
}
void ofApp::fight2(){
    ofSetColor(white,60);
    ofDrawCircle(0, height/2, height/2);
    nw.x++;
    ofSetColor(white );
    ofDrawRectangle(nw.x, nw.y, nww, nww);
    length=70;
    if (dis<200){
    dis+=(1000-dis)*s/3;
    }
    else{
        dis+=(-2000-dis)*s/3;
    }
    for (int i=0;i<8;i++){
        for (int n=0; n<8; n++) {
            int m=n*8+i;
                ofSetColor(sRandom[m]*60, sRandom[m]*12, sRandom[m]*18);
                ofDrawRectangle(ppl4[m].x+dis,ppl4[m].y,length,sRandom[m]);
                ofSetColor(sRandom[m]*5, sRandom[m]*34, sRandom[m]*88);
                ofDrawRectangle(ppl3[m].x+dis,ppl3[m].y,length,sRandom[m]);
                ofSetColor(sRandom[m]*10, sRandom[m]*22, sRandom[m]*88);
                ofDrawRectangle(ppl2[m].x+dis,ppl2[m].y,length,sRandom[m]);
            if(Move>800-0.1f){
                tri[6]=true;
                
            }
        }
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
    
    if(button==0){
        cout<<"click"<<endl;
        if(cue<2){
            frame[1]=ofGetFrameNum();
            //cout<<cue<<endl;
            cue=2;
            cout<<"cue="<<cue<<endl;
        }
        if(cue==2){
            cout<<cue<<endl;
            int mouseClick;
            c2Click++;
            //cout<<c2Click<<endl;
            mX=x;
            mY=y;
            cPpl1.set(x, y);
            cPpl0.set(x+rand()%12*20,y);
            if(c2Click>=1&&c2Click<4){
                cppl[c2Click-1].set(cPpl0.x,cPpl1.y);
            }
            if (c2Click==4){
                frame[2]=ofGetFrameNum();
                mX=x;
                mY=y;
                cue=3;
                cout<<"cue="<<cue<<endl;
            }
        }
        if (cue==3) {
            if (tri[3]) {
                mX=x;
                mY=y;
                for (int i=0;i<8;i++){
                    for (int n=0; n<8; n++) {
                    ppl[n*8+i].set(width/8*i+width/16+rand()%80-40, height/8*n+height/16+rand()%80-40);
                    int l=1+rand()%10;
                    sRandom[n*8+i]=(1+rand()%3)*5;
                    ppl3[n*8+i].set(ppl[n*8+i].x-width/5*l,ppl[n*8+i].y-height/5*l);
                    
                    }
                }
                frame[3]=ofGetFrameNum();
                cue=4;
                cout<<"cue="<<cue<<endl;
            }
        }
        if (cue==4) {
            if(tri[4]){
                mX=x;
                mY=y;
                for (int i=0;i<8;i++){
                    for (int n=0; n<8; n++) {
                        ppl[n*8+i].set(width/8*i+width/16+rand()%80-40, height/8*n+height/16+rand()%80-40);
                        int l=1+rand()%10;
                        sRandom[n*8+i]=(1+rand()%3)*5;
                        ppl4[n*8+i].set(ppl[n*8+i].x-width/5*l,ppl[n*8+i].y-height/5*l);
                        
                    }
                }
                    frame[4]=ofGetFrameNum();
                    cue=5;
                    cout<<"cue="<<cue<<endl;
                }
        }
        if (cue==5) {
            if(tri[5]){
                mX=x;
                mY=y;
                    frame[5]=ofGetFrameNum();
                    cue=6;
                    cout<<"cue="<<cue<<endl;
                }
        }
        if (cue==6) {
            if(tri[6]){
                mX=x;
                mY=y;
                    frame[6]=ofGetFrameNum();
                    cue=7;
                    cout<<"cue="<<cue<<endl;
                }
        }
        if (cue==8){
            back=true;
            
            mX=x;
            mY=y;
            
        }
        
   }
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
void ofApp::s1(){
    //fbo1.begin();
    if (rr) {
        r1+=s*(40-r1)/3;
        for (int i=0; i<=9; i++) {
            
            ofPushMatrix();
            ofTranslate(nw.x,nw.y);
            ofRotateZDeg(r1+40*i);
            
            ofSetColor(white,tran[i]);
            ofDrawRectangle(0,-nww*3.5f, nww, nww);
            
            ofTranslate(0, 0);
            ofPopMatrix();
        }
    }
    
    if(r1>40-0.1f){
        rr=false;
        r1+=4;
        
        for (int i=0; i<=9; i++) {
            ofPushMatrix();
            ofTranslate(nw.x,nw.y);
            ofRotateZDeg((i+1)*40-r1);
            if (r1<40*(i+1)) {
                    ofSetColor(white,tran[i]);
                    ofDrawRectangle(0,-nww*3.5f, nww, nww);
            }
            ofTranslate(0, 0);
            ofPopMatrix();
            if (r1>360) {
                cue=1;
                //cout<<"8"<<endl;
            }
            }
        }
        
    
    //fbo1.end();
    
    ofSetColor(white);
    
    
    
}
void ofApp::ClickGetM(int x, int y){
    mX=x;
    mY=y;
}
