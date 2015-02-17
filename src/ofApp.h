#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    // Video-grabber for "capture" the video frames
    ofVideoGrabber grabber;
    int w;// Width of the frame
    int h;// Height of the frame
    
    const int n = 20;// Number of harmonics
    ofSoundPlayer sample [20];// Samples of harmonics
    float volume [20];// Volume of harmonics
    int N [20];// Number of pixels in the play harmonica
    
    ofSoundPlayer sampleLoop;// Sample a drum loop
};
