#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//Создает пустую матрицу заданных размеров
int** createEmptyMatrix(int matrixRows, int matrixColumns) {
	int** createdMatrix = new int* [matrixRows];
	for (int i = 0; i < matrixRows; i++)
		createdMatrix[i] = new int[matrixColumns];
	return createdMatrix;
}

//Создает матрицу заполненную случайными значениями
int** createRandomMatrix(int matrixRows, int matrixColumns) {

	int** randomMatrix = createEmptyMatrix(matrixRows, matrixColumns);
	for (int i = 0; i < matrixRows; i++)
		for (int j = 0; j < matrixColumns; j++)
			randomMatrix[i][j] = rand() % 10;
	return randomMatrix;
}

//Выводит содержимое матрицы на экран
void printMatrix(int** matrix, int matrixRows, int matrixColumns) {
	for (int i = 0; i < matrixRows; i++)
	{
		for (int j = 0; j < matrixColumns; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

//Приводит переданную матрицу к необходимому размеру
int** castMatrix(int** matrix, int matrixRows, int matrixColumns, int dimensions) {
	int** castedMatrix = new int* [dimensions];
	for (int i = 0; i < dimensions; i++)
	{
		castedMatrix[i] = new int[dimensions];
		for (int j = 0; j < dimensions; j++)
			castedMatrix[i][j] = 0;
	}
	for (int i = 0; i < matrixRows; i++)
	{
		for (int j = 0; j < matrixColumns; j++)
			castedMatrix[i][j] = matrix[i][j];
	}
	return castedMatrix;
}

//Создает подматрицы заданного порядка
int** crateSubMatrix(int** castedMatrix, int dimensions, int tier) {
	int** subMatrix = new int* [dimensions / 2];
	switch (tier) {
	case(1): {
		for (int i = 0; i < dimensions / 2; i++)
		{
			subMatrix[i] = new int[dimensions / 2];
			for (int j = 0; j < dimensions / 2; j++)
				subMatrix[i][j] = castedMatrix[i][j];
		}
		break;
	}
	case(2): {
		for (int i = 0; i < dimensions / 2; i++)
		{
			subMatrix[i] = new int[dimensions / 2];
			for (int j = 0; j < dimensions / 2; j++)
				subMatrix[i][j] = castedMatrix[i][j + dimensions / 2];
		}
		break;
	}
	case(3): {
		for (int i = 0; i < dimensions / 2; i++)
		{
			subMatrix[i] = new int[dimensions / 2];
			for (int j = 0; j < dimensions / 2; j++)
				subMatrix[i][j] = castedMatrix[i + dimensions / 2][j];
		}
		break;
	}
	case(4): {
		for (int i = 0; i < dimensions / 2; i++)
		{
			subMatrix[i] = new int[dimensions / 2];
			for (int j = 0; j < dimensions / 2; j++)
				subMatrix[i][j] = castedMatrix[i + dimensions / 2][j + dimensions / 2];
		}
		break;
	}
	}
	return subMatrix;
}

//Создает матрицу перехода
int** createTransitionalMatrix(int changedMatrixDimensions) {
	int** transitionalMatrix = new int* [changedMatrixDimensions / 2];
	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		transitionalMatrix[i] = new int[changedMatrixDimensions / 2];
	}
	return transitionalMatrix;
}

//Создает вспомагательную матрицу
int** createSubsidiaryMatrix(int changedMatrixDimensions) {
	int** subsidiaryMatrix = new int* [changedMatrixDimensions / 2];
	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		subsidiaryMatrix[i] = new int[changedMatrixDimensions / 2];
	}
	return subsidiaryMatrix;
}

//Выравнивает результирующую матрицу
void adjustResultMatrix(int** resultMatrix, int changedMatrixDimensions, int* notZeroElementsAmount, int* firstFullZeroRow, int* firstFullZeroColumn) {
	for (int i = 0; i < changedMatrixDimensions; i++)
	{
		*notZeroElementsAmount = 0;
		for (int j = 0; j < changedMatrixDimensions; j++)
		{
			if (resultMatrix[i][j] != 0)
			{
				*notZeroElementsAmount = *notZeroElementsAmount + 1;
				*firstFullZeroRow = 100;
			}
		}
		if (*notZeroElementsAmount == 0 && i < *firstFullZeroRow)
		{
			*firstFullZeroRow = i;
		}
	}
	for (int i = 0; i < changedMatrixDimensions; i++)
	{
		*notZeroElementsAmount = 0;
		for (int j = 0; j < changedMatrixDimensions; j++)
		{
			if (resultMatrix[j][i] != 0)
			{
				*notZeroElementsAmount = *notZeroElementsAmount + 1;
				*firstFullZeroColumn = 100;
			}
		}
		if (*notZeroElementsAmount == 0 && i < *firstFullZeroColumn)
		{
			*firstFullZeroColumn = i;
		}
	}
}



void main()
{
	srand(time(NULL));
	int firstMatrixRows, firstMatrixColumns, secondMatrixRows, secondMatrixColumns, wayToFill, changedMatrixDimensions = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> firstMatrixRows >> firstMatrixColumns;
	} while (firstMatrixRows <= 0 || firstMatrixColumns <= 0);
	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> secondMatrixRows >> secondMatrixColumns;
	} while (secondMatrixRows <= 0 || secondMatrixColumns <= 0);

	int** firstInitialMatrix = createEmptyMatrix(firstMatrixRows, firstMatrixColumns);
	int** secondInitialMatrix = createEmptyMatrix(secondMatrixRows, secondMatrixColumns);

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> wayToFill;
	} while (wayToFill < 1 || wayToFill > 2);
	switch (wayToFill)
	{
	case 1:
		for (int i = 0; i < firstMatrixRows; i++)
			for (int j = 0; j < firstMatrixColumns; j++)
				cin >> firstInitialMatrix[i][j];
		for (int i = 0; i < secondMatrixRows; i++)
			for (int j = 0; j < secondMatrixColumns; j++)
				cin >> secondInitialMatrix[i][j];
		cout << "\nМатрица 1\n\n";
		for (int i = 0; i < firstMatrixRows; i++)
		{
			for (int j = 0; j < firstMatrixColumns; j++)
				cout << firstInitialMatrix[i][j] << " ";
			cout << endl;
		}
		cout << "\nМатрица 2\n\n";
		for (int i = 0; i < secondMatrixRows; i++)
		{
			for (int j = 0; j < secondMatrixColumns; j++)
				cout << secondInitialMatrix[i][j] << " ";
			cout << endl;
		}
		break;
	case 2:
		firstInitialMatrix = createRandomMatrix(firstMatrixRows, firstMatrixColumns);
		secondInitialMatrix = createRandomMatrix(secondMatrixRows, secondMatrixColumns);
		cout << "\nМатрица 1\n\n";
		printMatrix(firstInitialMatrix, firstMatrixRows, firstMatrixColumns);
		cout << "\nМатрица 2\n\n";
		printMatrix(secondInitialMatrix, secondMatrixRows, secondMatrixColumns);
		break;
	}

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (changedMatrixDimensions < firstMatrixRows || changedMatrixDimensions < secondMatrixRows || changedMatrixDimensions < firstMatrixColumns || changedMatrixDimensions < secondMatrixColumns)
		changedMatrixDimensions *= 2;

	int** firstCastedMatrix = castMatrix(firstInitialMatrix, firstMatrixRows, firstMatrixColumns, changedMatrixDimensions);
	int** secondCastedMatrix = castMatrix(secondInitialMatrix, secondMatrixRows, secondMatrixColumns, changedMatrixDimensions);

	cout << "Приведенные матрицы\n";
	cout << "\nМатрица 1\n\n";
	printMatrix(firstCastedMatrix, changedMatrixDimensions, changedMatrixDimensions);
	cout << "\nМатрица 2\n\n";
	printMatrix(secondCastedMatrix, changedMatrixDimensions, changedMatrixDimensions);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** firstMatrixFirstSubmatrix = crateSubMatrix(firstCastedMatrix, changedMatrixDimensions, 1);
	int** firstMatrixSecondSubmatrix = crateSubMatrix(firstCastedMatrix, changedMatrixDimensions, 2);
	int** firstMatrixThirdSubmatrix = crateSubMatrix(firstCastedMatrix, changedMatrixDimensions, 3);
	int** firstMatrixFourthSubmatrix = crateSubMatrix(firstCastedMatrix, changedMatrixDimensions, 4);

	int** secondMatrixFirstSubmatrix = crateSubMatrix(secondCastedMatrix, changedMatrixDimensions, 1);
	int** secondMatrixSecondSubmatrix = crateSubMatrix(secondCastedMatrix, changedMatrixDimensions, 2);
	int** secondMatrixThirdSubmatrix = crateSubMatrix(secondCastedMatrix, changedMatrixDimensions, 3);
	int** secondMatrixFourthSubmatrix = crateSubMatrix(secondCastedMatrix, changedMatrixDimensions, 4);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////////Создание промежуточных матриц//////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** firstTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** secondTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** thirdTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** fourthTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** fifthTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** sixthTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);
	int** seventhTransitionalMatrix = createTransitionalMatrix(changedMatrixDimensions);

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Вычисление значений промежуточных матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		for (int j = 0; j < changedMatrixDimensions / 2; j++)
		{
			firstTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				firstTransitionalMatrix[i][j] += (firstMatrixFirstSubmatrix[i][z] + firstMatrixFourthSubmatrix[i][z]) * (secondMatrixFirstSubmatrix[z][j] + secondMatrixFourthSubmatrix[z][j]);
			}

			secondTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				secondTransitionalMatrix[i][j] += (firstMatrixThirdSubmatrix[i][z] + firstMatrixFourthSubmatrix[i][z]) * secondMatrixFirstSubmatrix[z][j];
			}

			thirdTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				thirdTransitionalMatrix[i][j] += firstMatrixFirstSubmatrix[i][z] * (secondMatrixSecondSubmatrix[z][j] - secondMatrixFourthSubmatrix[z][j]);
			}

			fourthTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				fourthTransitionalMatrix[i][j] += firstMatrixFourthSubmatrix[i][z] * (secondMatrixThirdSubmatrix[z][j] - secondMatrixFirstSubmatrix[z][j]);
			}

			fifthTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				fifthTransitionalMatrix[i][j] += (firstMatrixFirstSubmatrix[i][z] + firstMatrixSecondSubmatrix[i][z]) * secondMatrixFourthSubmatrix[z][j];
			}

			sixthTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				sixthTransitionalMatrix[i][j] += (firstMatrixThirdSubmatrix[i][z] - firstMatrixFirstSubmatrix[i][z]) * (secondMatrixFirstSubmatrix[z][j] + secondMatrixSecondSubmatrix[z][j]);
			}

			seventhTransitionalMatrix[i][j] = 0;
			for (int z = 0; z < changedMatrixDimensions / 2; z++)
			{
				seventhTransitionalMatrix[i][j] += (firstMatrixSecondSubmatrix[i][z] - firstMatrixFourthSubmatrix[i][z]) * (secondMatrixThirdSubmatrix[z][j] + secondMatrixFourthSubmatrix[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** subsidiaryMatrix1 = createSubsidiaryMatrix(changedMatrixDimensions);
	int** subsidiaryMatrix2 = createSubsidiaryMatrix(changedMatrixDimensions);
	int** subsidiaryMatrix3 = createSubsidiaryMatrix(changedMatrixDimensions);
	int** subsidiaryMatrix4 = createSubsidiaryMatrix(changedMatrixDimensions);


	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		for (int j = 0; j < changedMatrixDimensions / 2; j++)
		{
			subsidiaryMatrix1[i][j] = firstTransitionalMatrix[i][j] + fourthTransitionalMatrix[i][j] - fifthTransitionalMatrix[i][j] + seventhTransitionalMatrix[i][j];
			subsidiaryMatrix2[i][j] = thirdTransitionalMatrix[i][j] + fifthTransitionalMatrix[i][j];
			subsidiaryMatrix3[i][j] = secondTransitionalMatrix[i][j] + fourthTransitionalMatrix[i][j];
			subsidiaryMatrix4[i][j] = firstTransitionalMatrix[i][j] - secondTransitionalMatrix[i][j] + thirdTransitionalMatrix[i][j] + sixthTransitionalMatrix[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** resultMatrix = new int* [changedMatrixDimensions];
	for (int i = 0; i < changedMatrixDimensions; i++)
	{
		resultMatrix[i] = new int[changedMatrixDimensions];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		for (int j = 0; j < changedMatrixDimensions / 2; j++)
		{
			resultMatrix[i][j] = subsidiaryMatrix1[i][j];
			resultMatrix[i][j + changedMatrixDimensions / 2] = subsidiaryMatrix2[i][j];
			resultMatrix[i + changedMatrixDimensions / 2][j] = subsidiaryMatrix3[i][j];
			resultMatrix[i + changedMatrixDimensions / 2][j + changedMatrixDimensions / 2] = subsidiaryMatrix4[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int notZeroElementsAmount = 0, firstFullZeroRow = 100, firstFullZeroColumn = 100;
	adjustResultMatrix(resultMatrix, changedMatrixDimensions, &notZeroElementsAmount, &firstFullZeroRow, &firstFullZeroColumn);

	int** matrixForPrint = new int* [firstFullZeroRow];
	for (int i = 0; i < firstFullZeroRow; i++)
	{
		matrixForPrint[i] = new int[firstFullZeroColumn];
		for (int j = 0; j < firstFullZeroColumn; j++)
			matrixForPrint[i][j] = resultMatrix[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	cout << "\nРезультирующая матрица\n\n";
	printMatrix(matrixForPrint, firstFullZeroRow, firstFullZeroColumn);


	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < firstMatrixRows; i++)
		delete[] firstInitialMatrix[i];
	for (int i = 0; i < secondMatrixRows; i++)
		delete[] secondInitialMatrix[i];
	for (int i = 0; i < changedMatrixDimensions; i++)
	{
		delete[] firstCastedMatrix[i];
		delete[] secondCastedMatrix[i];
		delete[] resultMatrix[i];
	}
	for (int i = 0; i < firstFullZeroRow; i++)
		delete[] matrixForPrint[i];
	for (int i = 0; i < changedMatrixDimensions / 2; i++)
	{
		delete[] firstMatrixFirstSubmatrix[i];
		delete[] firstMatrixSecondSubmatrix[i];
		delete[] firstMatrixThirdSubmatrix[i];
		delete[] firstMatrixFourthSubmatrix[i];
		delete[] secondMatrixFirstSubmatrix[i];
		delete[] secondMatrixSecondSubmatrix[i];
		delete[] secondMatrixThirdSubmatrix[i];
		delete[] secondMatrixFourthSubmatrix[i];
		delete[] subsidiaryMatrix1[i];
		delete[] subsidiaryMatrix2[i];
		delete[] subsidiaryMatrix3[i];
		delete[] subsidiaryMatrix4[i];
		delete[] firstTransitionalMatrix[i];
		delete[] secondTransitionalMatrix[i];
		delete[] thirdTransitionalMatrix[i];
		delete[] fourthTransitionalMatrix[i];
		delete[] fifthTransitionalMatrix[i];
		delete[] sixthTransitionalMatrix[i];
		delete[] seventhTransitionalMatrix[i];
	}
	delete[] firstInitialMatrix, secondInitialMatrix, firstCastedMatrix, secondCastedMatrix, resultMatrix, matrixForPrint;
	delete[] firstMatrixFirstSubmatrix, firstMatrixSecondSubmatrix, firstMatrixThirdSubmatrix, firstMatrixFourthSubmatrix, secondMatrixFirstSubmatrix, secondMatrixSecondSubmatrix, secondMatrixThirdSubmatrix, secondMatrixFourthSubmatrix, subsidiaryMatrix1, subsidiaryMatrix2, subsidiaryMatrix3, subsidiaryMatrix4;
	delete[] firstTransitionalMatrix, secondTransitionalMatrix, thirdTransitionalMatrix, fourthTransitionalMatrix, fifthTransitionalMatrix, sixthTransitionalMatrix, seventhTransitionalMatrix;
}