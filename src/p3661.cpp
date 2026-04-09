class Solution 
{
public:
    int maxWalls(std::vector<int>& robots, std::vector<int>& distance, 
            std::vector<int>& walls)
    {
        
    }
};

int main()
{
    return 0;
}

// Feels like a greedy problem
// What if robot close to wall has very high distance though and robot a bit away has tiny,
// and setup is like  R  RW    W
// Would want robot close to wall not to shoot it
// Therefore not greedy
//
// Could brute force with dp, checking every robot against every wall it can shoot
// Would be a massive table though
//
// Wait, didn't read problem properly
// Bullets destroy every wall in its path, not just one, and
// bullets stop upon reaching another robot
//
// So now order of shots no longer matters, just whether each robot should shoot left or right
//
