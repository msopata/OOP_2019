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
    StrictMock<MyMock> MyMock{};
    Dummy dummy{MyMock};
    EXPECT_CALL(MyMock, test()).WillOnce(Return(10));
    EXPECT_EQ(10, dummy.execute());

    TimeImpl myTime;

    StrictMock<TimeMock> timeMock{};
    StrictMock<SpaceMock> spaceMock{};
    StrictMock<ObserverMock> observerMock{};

    Universe universe = Universe( timeMock, spaceMock, observerMock);
    EXPECT_CALL(spaceMock, create(11));
    universe.create();


}
