#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI acos(-1.0)

enum Type {
    Square, Circle, Rectengle, Trapeze
};

struct Figure
{
    Type type;
    union CanBe
    {
        struct Square
        {
            int length;
        } square;
        struct Circle
        {
            int radius;
        } circle;
        struct Rectengle
        {
            int length;
            int width;
        } rectengle;
        struct Trapeze
        {
            int length;
            int heght;
        } trapeze;
    } canBe;
    double size;
};

struct Figure* createNewSquare(int length);
struct Figure* createNewCircle(int radius);
struct Figure* createNewRectengle(int length, int width);
struct Figure* createNewTrapeze(int length, int height);

void printFigures(Figure** figures, int size);
char* getEnumValue(enum Type type);

void countSize(Figure ** figures, int size);

int main()
{
    int size;
    printf("Enter the number of figures:\n");
    scanf("%d", &size);
    Figure **figures = (Figure**) calloc(size, sizeof(figures[0][0]));
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter number of your choise:\n"
        "\tFor Square enter 1, \n"
        "\tFor Circle enter 2, \n"
        "\tFor Rectengle enter 3, \n"
        "\tFor Trapeze enter 4 \n");
        int choise;
        scanf("%d", &choise);
        int value1, value2;
        switch (choise)
        {
        case 1:
            printf("Enter length:\n");
            scanf("%d", &value1);
            figures[i] = createNewSquare(value1);
            break;
        case 2:
            printf("Enter radius:\n");
            scanf("%d", &value1);
            figures[i] = createNewCircle(value1);
            break;
        case 3:
            printf("Enter length:\n");
            scanf("%d", &value1);
            printf("Enter width:\n");
            scanf("%d", &value2);
            figures[i] = createNewRectengle(value1, value2);
            break;
        case 4:
            printf("Enter length:\n");
            scanf("%d", &value1);
            printf("Enter width:\n");
            scanf("%d", &value2);
            figures[i] = createNewTrapeze(value1, value2);
            break;
        default:
            break;
        }
    }

    printFigures(figures, size);
    printf("\n-------------------------------------------\n");

    countSize(figures, size);

    printFigures(figures, size);
    printf("\n-------------------------------------------\n");
}

void countSize(Figure ** figures, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(figures[i]->type == Square)
        {
            figures[i]->size = (figures[i]->canBe.square.length) * (figures[i]->canBe.square.length);
        }
        if(figures[i]->type == Circle)
        {
            figures[i]->size = (figures[i]->canBe.circle.radius) * (figures[i]->canBe.circle.radius) * M_PI;
        }
        if(figures[i]->type == Rectengle)
        {
            figures[i]->size = (figures[i]->canBe.rectengle.length) * (figures[i]->canBe.rectengle.width);
        }
        if(figures[i]->type == Trapeze)
        {
            figures[i]->size = (figures[i]->canBe.trapeze.length) * (figures[i]->canBe.rectengle.width);
        }
    }
}

void printFigures(Figure** figures, int size)
{
    printf("-------------------------------------------\n");
    printf("TYPE        |   SIZE     |   DIMENSION\n");
    printf("-------------------------------------------\n");
    for(int i = 0; i < size; i++)
    {
        if(figures[i]->type == Square)
        {
            printf("%-15s%-15f%-5d\n", getEnumValue(figures[i]->type), figures[i]->size,
             figures[i]->canBe.square.length);
        }
        if(figures[i]->type == Circle)
        {
            printf("%-15s%-15f%-5d\n", getEnumValue(figures[i]->type), figures[i]->size, 
            figures[i]->canBe.circle.radius);
        }
        if(figures[i]->type == Rectengle)
        {
            printf("%-15s%-15f%-5d%-5d\n", getEnumValue(figures[i]->type), figures[i]->size,
                figures[i]->canBe.rectengle.length, figures[i]->canBe.rectengle.width);
        }
        if(figures[i]->type == Trapeze)
        {
            printf("%-15s%-15f%-5d%-5d\n", getEnumValue(figures[i]->type), figures[i]->size,
                figures[i]->canBe.trapeze.length, figures[i]->canBe.trapeze.heght);
        }
    }
}

char* getEnumValue(enum Type type)
{
    switch (type)
    {
        case Square: return "Square";
        case Rectengle: return "Rectengle";
        case Circle: return "Circle";
        case Trapeze: return "Trapeze";
    }
}

struct Figure* createNewSquare(int length)
{
    Figure *tempSquare = (Figure*) malloc(sizeof(tempSquare[0]));
    tempSquare->type = Square;
    tempSquare->canBe.square.length = length;
    return tempSquare;
}

struct Figure* createNewCircle(int radius)
{
    Figure *tempCircle = (Figure*) malloc(sizeof(tempCircle[0]));
    tempCircle->type = Circle;
    tempCircle->canBe.circle.radius = radius;
    return tempCircle;
}

struct Figure* createNewRectengle(int length, int width)
{
    Figure *tempRectengle = (Figure*) malloc(sizeof(tempRectengle[0]));
    tempRectengle->type = Rectengle;
    tempRectengle->canBe.rectengle.length = length;
    tempRectengle->canBe.rectengle.width = width;
    return tempRectengle;
}

struct Figure* createNewTrapeze(int length, int height)
{
    Figure *tempTrapeze = (Figure*) malloc(sizeof(tempTrapeze[0]));
    tempTrapeze->type = Trapeze;
    tempTrapeze->canBe.trapeze.length = length;
    tempTrapeze->canBe.trapeze.heght = height;
    return tempTrapeze;
}