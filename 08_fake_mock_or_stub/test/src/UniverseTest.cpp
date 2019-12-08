#include "Universe.h"
#include "TestIncludes.h"
#include "ObserverMock.h"
#include "TimeMock.h"
#include "SpaceMock.h"
#include "TimeImpl.h"


class Interface{
public:
   virtual int test() = 0;
};

class Implementation : public Interface{
public:
    int test() override {
        return 10;
    };
};

class Dummy{
private:
    Interface &interface;
public:
    explicit Dummy(Interface& interface) : interface(interface){};
    int execute( ){ return interface.test(); };
};

class MyMock : public Interface{
public:
    MOCK_METHOD0(test, int());
};


TEST(Universe, Create)
{
    StrictMock<TimeMock> time;
    StrictMock<SpaceMock> space;
    StrictMock<ObserverMock> observer;

    Universe universe(time, space, observer);

    EXPECT_CALL(time, create(true));
    EXPECT_CALL(space, create(11));
    EXPECT_CALL(space, dimensions()).WillOnce(Return(10));
    EXPECT_CALL(observer, remember("How many dimensions there are?", std::to_string(10)));
    universe.create();

}

TEST(Universe, Simulate)
{
    StrictMock<TimeMock> time;
    StrictMock<SpaceMock> space;
    StrictMock<ObserverMock> observer;

    Universe universe(time, space, observer);

    EXPECT_CALL(time, create(true));
    EXPECT_CALL(space, create(11));
    EXPECT_CALL(space, dimensions()).WillOnce(Return(11));
    EXPECT_CALL(observer, remember("How many dimensions there are?", std::to_string(11)));

    universe.create();

    EXPECT_CALL(time, now()).WillOnce(Return(9300000000)).WillOnce(Return(9900000000)).WillOnce(Return(13800000000)).WillOnce(Return(15000000000));
    EXPECT_CALL(time, flow()).Times(3);
    EXPECT_CALL(observer, remember("Is there planet Earth?", "Yes!"));
    EXPECT_CALL(observer, remember("Does life exist?", "Yes!"));
    EXPECT_CALL(observer, remember("Have People evolved?", "Yes!"));

    universe.simulate( 14999999999);
}
