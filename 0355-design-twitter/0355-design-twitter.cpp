class Twitter {
private:
    struct Tweet {
        int tweetId;
        int timestamp;

        Tweet(int id, int time) : tweetId(id), timestamp(time) {}
    };

    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, list<Tweet>> tweets;
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_front(tweetId, timestamp++);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> newsFeed;

        for (const auto& tweet : tweets[userId]) {
            maxHeap.push({tweet.timestamp, tweet.tweetId});
        }

        
        for (int followerId : followers[userId]) {
            for (const auto& tweet : tweets[followerId]) {
                maxHeap.push({tweet.timestamp, tweet.tweetId});
            }
        }

        
        while (!maxHeap.empty() && newsFeed.size() < 10) {
            newsFeed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return newsFeed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};