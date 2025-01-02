
class Solution {
public:

    int getMinDist(int chordCenter,int minEdge,int maxEdge){
        // if the center of a circle along the axis lies inside a rectangle
        if(chordCenter >= minEdge && chordCenter <= maxEdge)return 0;

        return chordCenter < minEdge ? minEdge - chordCenter : maxEdge - chordCenter;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        
        int x  = getMinDist(xCenter,x1,x2);
        int y = getMinDist(yCenter,y1,y2);

        return x*x + y*y <= radius * radius;
    }
};