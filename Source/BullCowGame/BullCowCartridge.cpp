// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Math/UnrealMathUtility.h"

//Constants||
const int LIVE_AMOUNT = 5;
//_________||

//Helper methods||
void UBullCowCartridge::WinningMessage(){
    PrintLine(TEXT("You found the secret word!"));
}

void UBullCowCartridge::LosingMessage(){

    this->currentLives--;

    if(this->currentLives <= 0){
        PrintLine(TEXT("You lost! Press any key to restart!"));
    }else{
        PrintLine(TEXT("Word is incorrect, you have 3 bulls and 4 cows"));
    }
}
//______________||

void UBullCowCartridge::InitGame(){
    int RandomNumber = FMath::RandRange(0, this->ListOfWords.Num() - 1);
    FString RandomWord = this->ListOfWords[RandomNumber];
    
    this->HiddenWord = RandomWord;
    this->currentLives = LIVE_AMOUNT;

    ClearScreen();
    PrintLine(TEXT("Welcome to the Bull Cows game!"));
    PrintLine(TEXT("The hidden word is " + FString::FromInt(RandomWord.Len()) + " letters long!"));
    PrintLine(TEXT("Insert your message: "));
}

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    this->InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(this->currentLives <= 0){
        this->InitGame();
        return;
    }

    ClearScreen();

    if(Input == HiddenWord)
        this->WinningMessage();
    else
        this->LosingMessage();

}