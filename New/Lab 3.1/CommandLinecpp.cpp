#include "Header.h"
#include <string>
#include <string.h>
// readme
// cmd 1 4 chưa xử lý phần đọc file
// chưa in các thông tin đầu vào của từng cmd
// chưa việt hàm ghi file output cmd 2
//
void CommandLine(char* argc, char* argv[])
{
	clock_t start, end;
	unsigned long long count_com = 0;

	string order[] = { "-rand", "-nsorted", "-sorted", "rev" };
	//string mode[] = { "-a", "-c" };
	string sort[] = { "selection-sort", "insertion-sort","merge-sort", "heap-sort", "bubble-sort", "quick-sort", "radix-sort", "shaker-sort", "shell-sort", "counting-sort", "flash-sort" };
	string parameters[] = { "-time", "-comp", "-both" };
	string DataSize[] = { "10000", "50000", "100000", "300000", "500000" };
	int n = atoi(argc);

	if (n > 6 && n < 5)
	{
		cout << "-------EROR-------" << endl;
	}
	else
	{
		if (n == 5)
		{

			std::string input(argv[3]), alg(argv[2]);
			string mode(argv[1]), parameter(argv[4]);


			bool check = false;
			if (mode == "-a")
			{
				int par = -1;
				if (parameter == "-time")
				{
					par = 0;
				}
				else if (parameter == "-comp")
				{
					par = 1;
				}
				else if (parameter == "-both")
				{
					par = 2;
				}
				else
					cout << "---------error---------" << endl;
				// ktra argv[3] có phải là số ?
				if (atoi(argv[3]) != 0)
					check = true;

				if (check == true)
				{
					//cmd 3
					int inputsize = atoi(argv[3]);
					int index = -1; // vị trí của sort trong string
					for (int i = 0; i < 11; i++)
					{
						if (alg == sort[i])
						{
							index = i;
							break;
						}
					}
					//
					switch (par)
					{
					case 0:
						// Run time
						for (int i = 0; i < 4; i++)
						{
							cout << order[i] << ":    ";
							int* a = new int[inputsize];
							GenerateData(a, inputsize, i);
							start = clock();
							MenuRunTime(a, inputsize, index);
							end = clock();
							double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
							cout << time << endl;
							delete a;
						}
						break;
					case 1:
						//comparison
						for (int i = 0; i < 4; i++)
						{
							cout << order[i] << ":    ";
							int* a = new int[inputsize];
							GenerateData(a, inputsize, i);
							long long count_com = 0;
							MenuComparison(a, inputsize, index, count_com);
							cout << count_com << endl;
							delete a;
						}
						break;
					case 2:
						// Runtime and comparison
						for (int i = 0; i < 4; i++)
						{
							cout << order[i] << ":    ";
							int* a = new int[inputsize];
							int* b = new int[inputsize];
							GenerateData(a, inputsize, i);
							copyArray(a, b, inputsize);
							//Runtime
							start = clock();
							MenuRunTime(a, inputsize, index);
							end = clock();
							double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
							cout << time << "  |   ";
							// Comparison
							long long count_com = 0;
							MenuComparison(a, inputsize, index, count_com);
							cout << count_com << endl;
							delete a, b;
						}
						break;
					default:
						break;
					}
				}
				else
				{
					//cmd 1

					// hàm đọc file
					int inputsize = 0;
					string dataorder;
					int indexorder = -1;
					//

					int index = -1; // vị trí của sort trong string
					for (int i = 0; i < 11; i++)
					{
						if (alg == sort[i])
						{
							index = i;
							break;
						}
					}

					//vitri dataorder trong string
					for (int i = 0; i < 4; i++)
					{
						if (dataorder == sort[i])
						{
							indexorder = i;
							break;
						}
					}

					switch (par)
					{
					case 0:
						// Run time
						cout << "Running time(if required): ";
						int* a = new int[inputsize];
						GenerateData(a, inputsize, indexorder);
						start = clock();
						MenuRunTime(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << endl;
						delete a;
						break;
					case 1:
						//comparison
						cout << "Comparsisions (if required): ";
						int* a = new int[inputsize];
						GenerateData(a, inputsize, indexorder);
						long long count_com = 0;
						MenuComparison(a, inputsize, index, count_com);
						cout << count_com << endl;
						delete a;
						break;
					case 2:

						// Runtime and comparison
						cout << "Running time(if required): ";
						int* a = new int[inputsize];
						int* b = new int[inputsize];
						GenerateData(a, inputsize, indexorder);
						copyArray(a, b, inputsize);
						//Runtime
						start = clock();
						MenuRunTime(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << endl;
						// Comparison
						cout << "Comparsisions (if required): ";
						long long count_com = 0;
						MenuComparison(a, inputsize, index, count_com);
						cout << count_com << endl;
						delete a, b;
						break;
					default:
						break;
					}
				}

			}
			if (mode == "-c")
			{
				//cmd 4
				string alg2 = input, alg1(argv[2]), inputfile(argv[4]);

				//
				// hàm đọc file
				int datasize = 0;
				//
				//

				int modedata = -1;

				int index_alg1 = -1, index_alg2 = -1;
				// ktra co trong sort[]
				for (int i = 0; i < 11; i++)
				{
					if (alg1 == sort[i]) index_alg1 = i;
					if (alg2 == sort[i]) index_alg2 = i;
				}
				// xác định order
				string order(argv[5]);
				if (order == "-rand")
				{
					modedata = 0;
				}
				else if (order == "-nsorted")
				{
					modedata = 3;
				}
				else if (order == "-sorted")
				{
					modedata = 1;
				}
				else if (order == "-rev")
				{
					modedata = 2;
				}
				else
					cout << "--------error-----" << endl;

				int* a = new int[datasize];
				GenerateData(a, datasize, modedata);
				int* b = new int[datasize];
				// runtime
				cout << "Running Time:   ";
				//alg1
				copyArray(a, b, datasize);
				start = clock();
				MenuRunTime(b, n, index_alg1);
				end = clock();
				double time1 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time1 << "  |   ";
				//alg2
				copyArray(a, b, datasize);
				start = clock();
				MenuRunTime(b, n, index_alg1);
				end = clock();
				double time2 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time2 << endl;

				// Comparison
				cout << "Comparisons:   ";
				//alg1
				copyArray(a, b, datasize);
				long long count_com = 0;
				MenuComparison(b, datasize, index_alg1, count_com);
				cout << count_com << "    |     ";
				// alg2
				copyArray(a, b, datasize);
				count_com = 0;
				MenuComparison(b, datasize, index_alg2, count_com);
				cout << count_com << endl;
			}
		}
		else if (n == 6)
		{
			string mode(argv[1]);
			int modedata = -1;
			// xác định mode
			if (mode == "-a")
			{
				// xác định order
				string order(argv[4]);
				if (order == "-rand")
				{
					modedata = 0;
				}
				else if (order == "-nsorted")
				{
					modedata = 3;
				}
				else if (order == "-sorted")
				{
					modedata = 1;
				}
				else if (order == "-rev")
				{
					modedata = 2;
				}
				else
					cout << "--------error-----" << endl;
				// xác định parameter
				string parameter(argv[5]);
				int par = -1;
				if (parameter == "-time")
				{
					par = 0;
				}
				else if (parameter == "-comp")
				{
					par = 1;
				}
				else if (parameter == "-both")
				{
					par = 2;
				}
				else
					cout << "---------error---------" << endl;
				// xác định datasize
				int inputsize = atoi(argv[3]);

				//xác định thuật toán
				string alg(argv[2]);
				int index = -1; // vị trí của sort trong string
				for (int i = 0; i < 11; i++)
				{
					if (alg == sort[i])
					{
						index = i;
						break;
					}
				}

				//CMD 2
				switch (par)
				{
				case 0:
					// Run time
					for (int i = 0; i < 4; i++)
					{
						cout << order[i] << ":    ";
						int* a = new int[inputsize];
						GenerateData(a, inputsize, i);
						start = clock();
						MenuRunTime(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << endl;
						delete a;
					}
					break;
				case 1:
					//comparison
					for (int i = 0; i < 4; i++)
					{
						cout << order[i] << ":    ";
						int* a = new int[inputsize];
						GenerateData(a, inputsize, i);
						long long count_com = 0;
						MenuComparison(a, inputsize, index, count_com);
						cout << count_com << endl;
						delete a;
					}
					break;
				case 2:
					// Runtime and comparison
					for (int i = 0; i < 4; i++)
					{
						cout << order[i] << ":    ";
						int* a = new int[inputsize];
						int* b = new int[inputsize];
						GenerateData(a, inputsize, i);
						copyArray(a, b, inputsize);
						//Runtime
						start = clock();
						MenuRunTime(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << "  |   ";
						// Comparison
						long long count_com = 0;
						MenuComparison(a, inputsize, index, count_com);
						cout << count_com << endl;
						delete a, b;
					}
					break;
				default:
					break;
				}
			}
			if (mode == "-c")
			{
				//cmd5
				int modedata = -1, datasize = atoi(argv[4]);
				string alg1(argv[2]), alg2(argv[3]);
				int index_alg1 = -1, index_alg2 = -1;
				// ktra co trong
				for (int i = 0; i < 11; i++)
				{
					if (alg1 == sort[i]) index_alg1 = i;
					if (alg2 == sort[i]) index_alg2 = i;
				}
				string order(argv[5]);
				if (order == "-rand")
				{
					modedata = 0;
				}
				else if (order == "-nsorted")
				{
					modedata = 3;
				}
				else if (order == "-sorted")
				{
					modedata = 1;
				}
				else if (order == "-rev")
				{
					modedata = 2;
				}
				else
					cout << "--------error-----" << endl;

				int* a = new int[datasize];
				GenerateData(a, datasize, modedata);
				int* b = new int[datasize];
				// runtime
				cout << "Running Time:   ";

				//alg1
				copyArray(a, b, datasize);
				start = clock();
				MenuRunTime(b, n, index_alg1);
				end = clock();
				double time1 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time1 << "  |   ";

				//alg2
				copyArray(a, b, datasize);
				start = clock();
				MenuRunTime(b, n, index_alg1);
				end = clock();
				double time2 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time2 << endl;

				
				// Comparison
				cout << "Comparisons:   ";

				//alg1
				copyArray(a, b, datasize);
				long long count_com = 0;
				MenuComparison(b, datasize, index_alg1, count_com);
				cout << count_com << "    |     ";

				// alg2
				copyArray(a, b, datasize);
				count_com = 0;
				MenuComparison(b, datasize, index_alg2, count_com);
				cout << count_com << endl;
			}
		}

	}

}