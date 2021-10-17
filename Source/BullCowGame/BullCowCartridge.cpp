// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Math/UnrealMathUtility.h"

//Constants||
const TArray<FString> ListOfWords {"cake", "pen", "red", "black", "water"};
const FString WINNING_MESSAGE = TEXT("You found the secret word!");
const FString LOSING_MESSAGE = TEXT("You lost!");
//_________||

//Variables||
int amountOfLives = 10;
//_________||

//Helper methods||
void UBullCowCartridge::WinningMessage(){
    PrintLine(WINNING_MESSAGE);
}

void UBullCowCartridge::LosingMessage(){
    PrintLine(LOSING_MESSAGE);
}
//______________||

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    int RandomNumber = FMath::RandRange(0, ListOfWords.Num() - 1);
    FString RandomWord = ListOfWords[RandomNumber];
    this->HiddenWord = RandomWord;

    PrintLine(TEXT("Welcome to the Bull Cows game!"));
    PrintLine(TEXT("The hidden word is " + FString::FromInt(RandomWord.Len()) + " letters long!"));
    PrintLine(TEXT("Insert your message: "));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if(Input == HiddenWord)
        this->WinningMessage();
    else
        this->LosingMessage();

}