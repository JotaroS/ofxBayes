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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		map<int, float> _map;
};




class ofxBayesHist{
  public:
	map<int, float> _map;
	ofxBayesHist();
	ofxBayesHist(map<int, float> _map){
		this->_map = _map;
	};
	void initialize(int _initMode = 0){
		for (std::pair<const int, float> &p : this->_map)
			_map[p.first] = 1.f;
		this->normalize();
	};
	void normalize(){
		auto sum = 0.f;
		for (std::pair<const int, float> &p : this->_map)
			sum += p.second;
		for (std::pair<const int, float> &p : this->_map)
			_map[p.first] /= sum;
	};
	void update(int data){
		for (std::pair<const int, float> &p : this->_map)
			_map[p.first] = p.second*likelihoodFunc(data, p.first);
		this->normalize();
	};
	void disp(string msg = "")
	{
		cout << "---" << msg << "---" << endl;
		for (std::pair<const int, float> &p : this->_map)
			std::cout << p.first << " => " << p.second << '\n';
	};
	function<float(int, int)> likelihoodFunc = [=](int a, int b) {
		cout << "WARNING : LIKELIHOOD FUNCTION NOT IMPLEMENTED" << endl;
		return 0.f;
	};
};
