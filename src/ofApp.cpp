#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    w = 320;
    h = 240;
    grabber.initGrabber(w, h);
    
    //Grab samples harmonics
    for(int i = 0; i<n; i++){
        int freq = (i+30);
        sample[i].loadSound("DM-FX05_"+ofToString(freq)+".wav");
        sample[i].setVolume(0);
        sample[i].setLoop(true);
        sample[i].play();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    if(!grabber.isFrameNew()){
        for(int i = 0; i < n; i++){
            volume[i] = 0;
            N[i] = 0;
        }
        unsigned char * input = grabber.getPixels();
        for(int y = 0; y<h ; y++){
            for (int x=0; x<w; x++) {
                int r = input[3*(x+w*y)+0];
                int g = input[3*(x+w*y)+1];
                int b = input[3*(x+w*y)+2];
                int result = (r+g+b>100)? 0:1;
                int i = (x*n/w);
                volume[i] += result;
                N[i]++;
            }
        }
        
        //set new volume
        for(int i = 0; i<n; i++){
            if(N[i]>0){
                volume[i] /= N[i]; //normalize volume
            }
            sample[i].setVolume(volume[i] / n); // Divide by n, otherwise it will be distortion of the output sound
        }
    }
    
    ofSoundUpdate();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    float w = ofGetWidth();
    float h = ofGetHeight();
    
    ofSetColor(255);
    grabber.draw(0, 0, w, h);
    
    //
    
    ofEnableAlphaBlending();
    ofSetColor(0, 255, 0, 80);
    for(int i = 0; i<n ; i++){
        float harmH = volume[i]*h;
        ofRect(i*w/n, h - harmH, w/n, harmH);
    }
    ofDisableAlphaBlending();

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
