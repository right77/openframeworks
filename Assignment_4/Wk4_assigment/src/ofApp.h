#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    
        void mouth();
        void mouth2();
        void setXMouth(int m,int n,int p, int q);
        void setYMouth(int m,int n,int p, int q);
    
        void eyes();
        void seteyes(int m, int n);
        
        void eyebrows();
        void setXEyebrows(int m,int n,int p, int q);
        void setYEyebrows(int m,int n,int p, int q);
    
        void happiness();
        void sad();
        void surprise();
        void anger();

        
		
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
    
        
};
