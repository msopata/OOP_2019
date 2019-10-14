#include "TestIncludes.h"
#include "TextWrapper.h"




TEST(TextWrapper, CreateInstance) {

    auto wrapper = TextWrapper{};
}

TEST(TextWrapper, HasColumnGetter) {

    auto wrapper = TextWrapper{};
    EXPECT_EQ(1, wrapper.columns() );
}

TEST(TextWrapper, HasContructorColumnsParam) {

    auto wrapper = TextWrapper{ 2, "" };
    EXPECT_EQ(2, wrapper.columns() );
    wrapper = TextWrapper{ 10, "a"};
    EXPECT_EQ(10, wrapper.columns() );
}

TEST(TextWrapper, HasTextGetter) {

    auto wrapper = TextWrapper{};
    EXPECT_EQ("", wrapper.text() );
}

TEST(TextWrapper, HasConstructorTextParam) {

    auto wrapper = TextWrapper(10, "xxx");
    EXPECT_EQ("xxx", wrapper.text() );
}

TEST(TextWrapper, HasWrapMethod) {

    auto wrapper = TextWrapper(1, "");
    EXPECT_EQ("", wrapper.wrap() );
}



//
// Created by student on 14.10.2019.
//

