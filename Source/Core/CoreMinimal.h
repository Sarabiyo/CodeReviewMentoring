#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <map>
#include <vector>

using namespace std;


/** 의도적으로 코드를 Unreal과 비슷하게 최대한 맞춤*/

#define UENUM(...)
#define USTRUCT(...)
#define UCLASS(...)
#define UPROPERTY(...)
#define UFUNCTION(...)

#define GENERATED_BODY()

using int32 = int;
using FString = std::string;
using FText = FString;			// 임시