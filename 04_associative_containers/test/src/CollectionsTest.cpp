#include "TestIncludes.h"

// TODO: ....

TEST(SetInt, RemoveElements) {

    std::set<int> set {1,2,3};

    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));

    std::set<int>::iterator it = set.begin();
    set.erase(++it);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(0u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
}

TEST(SetDouble, ElementsSortedWhenIterating) {

    // TODO: ....
    std::set<double> set;


    ASSERT_TRUE(set.empty());

    // TODO: ....
    std::set<double>::iterator it = set.begin();
    set.insert(it, 3.3);
    set.insert(it, 2.2);

    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));


    // TODO: ....
    set.insert(it, 4.4);
    set.insert(it, 1.1);

    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(3.3));
    EXPECT_EQ(1u, set.count(2.2));
    EXPECT_EQ(1u, set.count(4.4));
    EXPECT_EQ(1u, set.count(1.1));

    // TODO: ....
    set.insert(0.0);
    auto iter = set.begin();

    EXPECT_EQ(0.0, *iter++);
    EXPECT_EQ(1.1, *iter++);
    EXPECT_EQ(2.2, *iter++);
    EXPECT_EQ(3.3, *iter++);
    EXPECT_EQ(4.4, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetString, ElementsSortedInReversedAplhabeticalOrderWhenIterating) {

    struct Comparator {
        bool operator()(const std::string& lhs, const std::string& rhs) const {
            return lhs > rhs;
        }
    };

    // TODO: ....
    std::set<std::string, Comparator> set;
    set.insert("Bb");
    set.insert("Ba");
    set.insert("Ab");
    set.insert("Aa");

    auto iter = set.begin();
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);

    // TODO: ....
    set.insert("Ca");
    iter = set.begin();
    EXPECT_EQ("Ca", *iter++);
    EXPECT_EQ("Bb", *iter++);
    EXPECT_EQ("Ba", *iter++);
    EXPECT_EQ("Ab", *iter++);
    EXPECT_EQ("Aa", *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(SetInt, InvalidComparatorThatCausesOnlyOneElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const {
            return lhs > rhs;
        }
    };

    // TODO: ....
    std::set<int, Comparator> set;
    ASSERT_TRUE(set.empty());

    // TODO: ....
    set.insert(1);
    ASSERT_EQ(1u, set.size());

    // TODO: ....
    set.insert(1);
    ASSERT_EQ(1u, set.size());
}

TEST(SetInt, InvalidComparatorThatCausesMultipleCopiesOfTheSameElementToBeInserted) {

    struct Comparator {
        bool operator()(const int& lhs, const int& rhs) const {
            return lhs >= rhs;
        }
    };

    // TODO: ....
    std::set<int, Comparator> set;
    ASSERT_TRUE(set.empty());

    // TODO: ....
    set.insert(1);
    ASSERT_EQ(1u, set.size());

    // TODO: ....
    set.insert(1);
    ASSERT_EQ(2u, set.size());
}

TEST(SetValue, CustomTypeAndComparator) {

    struct Value {
        int _x;
        int _y;
        Value(int x, int y) : _x(x), _y(y) {}
    };

    struct Comparator {
        bool operator()(const Value& lhs, const Value& rhs) const {
            if(lhs._x == rhs._x ) return lhs._y > rhs._y;
                    return lhs._x > rhs._x;
        }
    };

    // TODO: ....
    std::set<Value, Comparator> set;
    ASSERT_TRUE(set.empty());

    // TODO: ....
    set.insert({3,0});
    ASSERT_EQ(1u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));

    // TODO: ....
    set.insert({6,0});
    ASSERT_EQ(2u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));

    // TODO: ....
    set.insert({3,3});
    ASSERT_EQ(3u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));

    // TODO: ....
    set.insert({6,6});
    ASSERT_EQ(4u, set.size());
    EXPECT_EQ(1u, set.count(Value{3, 0}));
    EXPECT_EQ(1u, set.count(Value{6, 0}));
    EXPECT_EQ(1u, set.count(Value{3, 3}));
    EXPECT_EQ(1u, set.count(Value{6, 6}));
}

TEST(SetInt, ElementsGreaterThanGivenValue) {

    // TODO: ....
    std::set<int> set {1,2,3,4,5};
    ASSERT_EQ(5u, set.size());
    EXPECT_EQ(1u, set.count(1));
    EXPECT_EQ(1u, set.count(2));
    EXPECT_EQ(1u, set.count(3));
    EXPECT_EQ(1u, set.count(4));
    EXPECT_EQ(1u, set.count(5));

    // TODO: ....
    auto iter = set.begin();
    for(int i=0; i < set.size(); i++)
        if( *iter < 3) iter++;


    EXPECT_EQ(3, *iter++);
    EXPECT_EQ(4, *iter++);
    EXPECT_EQ(5, *iter++);
    EXPECT_EQ(set.end(), iter);
}

TEST(MapStringString, CreateUsingInitializerList) {

    // TODO: ....
    std::map<std::string, std::string> map{{"CN", "China"}, {"GR", "Greece"}, {"FR", "France"}};
    ASSERT_EQ(3u, map.size());
    EXPECT_EQ("China", map["CN"]);
    EXPECT_EQ("Greece", map["GR"]);
    EXPECT_EQ("France", map["FR"]);
}

TEST(MapMapStringInt, NestedCollections) {

    // TODO: ....
    std::map<std::string, std::map<std::string, int>> map;
    ASSERT_TRUE(map.empty());

    // TODO: ....
    map["count"];
    ASSERT_EQ(1u, map.size());
    ASSERT_EQ(1u, map.count("count"));

    map["count"] = { std::map<std::string, int> {{"1", 12}, {"2", 4}, {"3", 2}, {"4", 7}} };

    ASSERT_EQ(4u, map["count"].size());
    EXPECT_EQ(12, map["count"]["1"]);
    EXPECT_EQ(4, map["count"]["2"]);
    EXPECT_EQ(2, map["count"]["3"]);
    EXPECT_EQ(7, map["count"]["4"]);

}

TEST(MultisetInt, RemoveRangeOfElements) {

    // TODO: ....
    std::multiset<int> multiset {1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3};
    ASSERT_EQ(16, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(12, multiset.count(2));
    EXPECT_EQ(3, multiset.count(3));

    // TODO: ....
    multiset.erase(2);
    ASSERT_EQ(4, multiset.size());
    EXPECT_EQ(1, multiset.count(1));
    EXPECT_EQ(3, multiset.count(3));
}
/*
TEST(UnorderedSetValue, CustomTypeHashAndComparator) {

    struct Value {
        int _x, _y, _z;
        Value(int x, int y, int z) : _x(x), _y(y), _z(z) {}
    };

    struct Hash {
        // TODO: ....
    };

    struct Equal {
        // TODO: ....
    };

    // TODO: ....

    ASSERT_TRUE(unordered_set.empty());

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));

    // TODO: ....

    ASSERT_EQ(8u, unordered_set.size());
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 1}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{1, 2, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 1, 2}));
    EXPECT_EQ(1u, unordered_set.count(Value{2, 2, 2}));
}
/*
TEST(UnorderedSetInt, BucketsAndLoadFactor) {

    // TODO: ....

    ASSERT_EQ(1u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0 / 2.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(2u, unordered_set.size());
    EXPECT_EQ(2u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(3u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(3.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(4u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(4.0 / 5.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(5u, unordered_set.size());
    EXPECT_EQ(5u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(10u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(10.0 / 11.0, unordered_set.load_factor());
    EXPECT_FLOAT_EQ(1.0f, unordered_set.max_load_factor());

    // TODO: ....

    ASSERT_EQ(11u, unordered_set.size());
    EXPECT_EQ(11u, unordered_set.bucket_count());
    EXPECT_FLOAT_EQ(11.0 / 11.0, unordered_set.load_factor());
}
*/