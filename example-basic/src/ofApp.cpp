#include "ofApp.h"

// here, let's solve "Monty hall problem."

//--------------------------------------------------------------
void ofApp::setup(){
    //# MONTY HALL PROBLEM #
    //You have a chance to get a prize.
    //There are doors named 0,1,2. Assume Audi A8 is only in one door in three.
    //Otherwise there are sheeps in two doors. Meh.
    //You definitely want A8. Assume here you choose door[0].
    //Then Hr.Monty opens door[1] to entertain the show, door[1] had a sheep. Meh.

    //Question : Again, you definitely want A8. Will you change your choise?

    //initialize probability of Audi in the door. so 1/3 each.
    _map[0] = 0.f;
    _map[1] = 0.f;
    _map[2] = 0.f;
    ofxBayesHist hist(_map);
    hist.initialize(); // initialize done. Now you get priori probability.
    hist.disp("Prior probability");

    //Now, you have to write your own Likelihood Function.
    //Remember, according to Bayes's theorem, posteriori-pribability is propotional to its Likelihood function.
    //Here, we want to know this for each i's.
    //
    // P(A8 on door[i]|Monty opened door[1]) 8= P(A8 on door[i]) * P(Monty openes door[1]|A8 on door[i])
    //
    //Likelihood function is now: P(Monty openes door[1]|A8 on door[i]).
    //Hense, Likelihood Function is given as:
    int choise = 0;
    hist.likelihoodFunc = [=](int data, int hypo) { //data is # of door opened by Monty. hypo is i written above.
        
        //first, equivalent code below

        // if(hypo == 0)
        //     return 0.5f; // Monty can open both 1,2. Give same probability for each.
        // else if(hypo == 1)
        //     return 0.f;  // Monty cannot open door 1 if there's A8 in door 1.
        // else if(hypo == 2)
        //     return 1.f; // Monty has no choise but open the door 1.
        // return 0.f;

        // here i write the same way.
        if (hypo == data)
            return 0.f; //monty cannot open the door if there's A8.
        else
        {
            if (hypo == choise)
                return 0.5f; //if you choose the door which there's A8, Monty can open the rest of the door at the same prob.
            else
                return 1.f; //Monty has no choise but open the door.
        }
    };

    // Now let's update the probability, that is, make posteriori probability.
    // Monty opened door 1 here.
    hist.update(1);
    hist.disp("Posterior probability");

    //Check the console output.
    // ---Priori probability---
    // 0 => 0.333333
    // 1 => 0.333333
    // 2 => 0.333333
    // ---Posteriori probability---
    // 0 => 0.333333
    // 1 => 0
    // 2 => 0.666667 <-

    //Answer : You will change your choise to get A8 for better guess.
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
