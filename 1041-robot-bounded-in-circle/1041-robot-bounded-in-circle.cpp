class Solution {
public:
    bool isRobotBounded(string instructions) {
        char dir = 'N';
        int x = 0, y = 0;
        
        for(char c: instructions){
            if(c == 'G'){
                if(dir == 'N') y+=1;
                else if(dir == 'S')  y-=1;
                else if(dir == 'E') x+=1; 
                else if(dir == 'W') x-=1;
            }
            else if(c == 'L'){
                if(dir=='N') dir='W';
                else if(dir=='S') dir='E';
                else if(dir=='E') dir='N';
                else if(dir=='W') dir='S';
            }
             else if(c=='R')
            {
                if(dir=='N') dir='E';
                else if(dir=='S') dir='W';
                else if(dir=='E') dir='S';
                else if(dir=='W') dir='N';
            }
        }
        
        //if x=0 and y=0, we are back at origin so return true
        if(x == 0 and y == 0) return true;
        
        //if dir is not North then it will return to origin after multiple repetitions.
        if(dir != 'N') return true;
        
        //if dir is North then it will never return even after multiple repetitons
        return false;
    }
};