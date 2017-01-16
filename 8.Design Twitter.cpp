class Twitter {
private:
    struct user_tweet{
        int userId;
        int tweetId;
    };
    
    vector<user_tweet> every_tweet;  //pair is userId + tweetId
    map<int,set<int>> follow_map;    //users following relationship
    
    int max_news;

public:
    /** Initialize your data structure here. */
    Twitter() {
        max_news = 10;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        user_tweet temp = {userId,tweetId};
        every_tweet.push_back(temp);
        
        //make user to follow himself
        follow(userId,userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        if(every_tweet.size() == 0)
            return result;
        else if(follow_map.find(userId) == follow_map.end())
            return result;
        else{
            int size = every_tweet.size();
            int count = 0;
            for(int i = size - 1; i >= 0; i--){
                if(count >= max_news)
                    break;
                
                int userFollowId = every_tweet[i].userId;
                int tweetId = every_tweet[i].tweetId;
                
                if(follow_map[userId].find(userFollowId) != follow_map[userId].end()){
                    result.push_back(tweetId);
                    count++;
                }
            }
            return result;
        }
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(follow_map.find(followerId) == follow_map.end()){
            set<int> new_followee;
            new_followee.insert(followeeId);
            follow_map.insert(make_pair(followerId,new_followee));
        }
        else{
            follow_map[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
            
        if(follow_map.find(followerId) != follow_map.end()){
            if(follow_map[followerId].find(followeeId) != follow_map[followerId].end())
                follow_map[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
