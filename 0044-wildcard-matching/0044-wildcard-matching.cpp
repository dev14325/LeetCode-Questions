class Solution {
public:
 
    bool solve(string s, string p , int i, int j)
    {
        //both pattern and string are consumed
        if(i<0 && j<0)
        {
            return true;
        }
        //if my pattern is consumed but my pattern is not consumed
        if(i>=0 && j<0)
        {
            return false;
        }

        // if string is consumed and pattern is remaining then
        // 2 cases
        // s = abc , p = babc || s= abc , p *abc
        //1st is invalid another is valid
        if(i<0 && j>=0)
        {
            //check for * if not present then invalid
            for(int k =0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }

            return true;
        }

        if(s[i]==p[j] || p[j]=='?')
        {
            return solve(s,p,i-1,j-1);
        }
        else if(p[j]=='*')
        {
            // instead of * we put  ""
            // i will remain there but j slides
            bool emptyPattern = solve(s,p,i,j-1);
            bool placingPattern = solve(s,p,i-1,j);

            return emptyPattern || placingPattern;
        }
        else
        {
            return false;
        }
    }
    //note pass it by reference
     bool solveMem(string &s, string &p , int i, int j,vector<vector<int>> & dp)
    {
        //both pattern and string are consumed
        if(i<0 && j<0)
        {
            return true;
        }
        //if my pattern is consumed but my pattern is not consumed
        if(i>=0 && j<0)
        {
            return false;
        }

       

        // if string is consumed and pattern is remaining then
        // 2 cases
        // s = abc , p = babc || s= abc , p *abc
        //1st is invalid another is valid
        if(i<0 && j>=0)
        {
            //check for * if not present then invalid
            for(int k =0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }

            return true;
        }

         if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=solveMem(s,p,i-1,j-1,dp);
        }
        else if(p[j]=='*')
        {
            // instead of * we put  ""
            // i will remain there but j slides
            bool emptyPattern = solveMem(s,p,i,j-1,dp);
            bool placingPattern = solveMem(s,p,i-1,j,dp);

            return dp[i][j]=(emptyPattern || placingPattern);
        }
        else
        {
            return dp[i][j]=false;
        }
    }
    bool isMatch(string s, string p) {

        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solveMem(s,p,s.size()-1, p.size()-1,dp);
        
    }
};