class Solution {
public:
    int numJewelsInStones_naiveMap(string jewels, string stones)
    {
        bool *jewels_map = new bool[58]();
        // 'A' = 65, 'z' = 127 | https://en.cppreference.com/w/cpp/language/ascii
        // the end brackets () ensures default initialization to false 
        int stones_count=0;
        
        for (int i=0; i<jewels.length(); i++)
            jewels_map[jewels[i]-'A']=true;
        
        for (int i=0; i<stones.length(); i++)
        {
            //cout<<i<<" | "<< stones[i] <<" | "<< stones[i]-'A' <<" | "<< jewels_map[stones[i]-'A']<<endl;
            if (jewels_map[stones[i]-'A'])
                stones_count++;
        }
        
        return stones_count;
    }
    
    int numJewelsInStones_map(string jewels, string stones)
    {
        map<char,int> jewels_map;
        int stones_count=0;
        
        for (int i=0; i<jewels.length(); i++)
            jewels_map[jewels[i]]=true;
        
        for (int i=0; i<stones.length(); i++)
        {
            if (jewels_map[stones[i]]>0)
                stones_count++;
        }
        
        return stones_count;
    }
    
    int numJewelsInStones_mapFast(string jewels, string stones) // 
    {
        map<char,int> jewels_map;
        int stones_count=0;
        
        for (char jewels_i:jewels)
            jewels_map[jewels_i]=true;
        
        for (char stones_i:stones)
        {
            if (jewels_map[stones_i]>0)
                stones_count++;
        }
        
        return stones_count;
    }
    
    int numJewelsInStones_set_verySlow(string jewels, string stones)
    {
        unordered_set<char> jewels_set;
        int stones_count=0;
        
        for (char jewels_i:jewels)
            jewels_set.insert(jewels_i);
        
        for (char stones_i:stones)
        {
            if (jewels_set.find(stones_i) != jewels_set.end())
                stones_count++;
        }
        
        return stones_count;
    }
    
    int numJewelsInStones(string jewels, string stones) // fastest
    {
        int stones_count=0;
        
        for (char stones_i:stones)
        {
            if (find(jewels.begin(),jewels.end(),stones_i) != jewels.end())
                stones_count++;
        }
        return stones_count;
    }
};