#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    void Motion(int n);
    void MoveNw(float m, float n);
    void DrawNwa(float m,float n,bool bWH);
    void drawPeople();
    void creatPeople(int x,int y);
    void ClickGetM(int x, int y);
    void Escape();
    void Meet();
    void Fight();
    void Fight2();
    //--------------------------------
    //Narratin 旁白
    void Narration(int i);
    void drawString(int NumLines);//旁白行数
    //--------------------------------
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void s1();
    ofTrueTypeFont    title;
    ofTrueTypeFont text;
    
    
};
