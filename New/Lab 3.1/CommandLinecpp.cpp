#include "Header.h"
#include <string>
#include <string.h>
// readme
// cmd 1 4 chưa xử lý phần đọc file
// chưa in các thông tin đầu vào của từng cmd
// chưa việt hàm ghi file output cmd 2
//

void CommandLine(int argc, const char* argv[])
{
	clock_t start, end;
	unsigned long long count_com = 0;

	string order[] = { "-sorted", "-nsorted", "-rev", "-rand" };
	//string mode[] = { "-a", "-c" };
	string sort[] = { "selection-sort", "heap-sort","bubble-sort", "insertion-sort", "radix-sort", "shaker-sort", "merge-sort", "quick-sort", "shell-sort", "counting-sort", "flash-sort" };
	string parameters[] = { "-time", "-comp", "-both" };
	string DataSize[] = { "10000", "30000", "50000", "100000", "300000", "500000"};
	int n = argc;


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

					cout << "AlGORITHM MODE : " << mode << endl;
					cout << "Algorithm : " << alg << endl;
					cout << "Input size : " << input <<"\n \n \n"<< endl;
					//

					switch (par)
					{
					case 0:
						// Run time
						for (int i = 0; i < 4; i++)
						{
							cout << "--------------------------------" << endl;
							cout << order[i] << endl;
							cout << "Running Time(if required):   ";
							int* a = new int[inputsize];
							GenerateData(a, inputsize, i);
							writeFileArray(a, inputsize, i + 2);
							start = clock();
							pickSort(a, inputsize, index);
							end = clock();
							double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
							cout << time << " ( ms )" << endl;
							delete a;
						}
						break;
					case 1:
						//comparison
						for (int i = 0; i < 4; i++)
						{
							cout << "--------------------------------" << endl;
							cout << order[i] << endl;
							cout << "Comparisions (if required):  ";
							int* a = new int[inputsize];
							GenerateData(a, inputsize, i);
							writeFileArray(a, inputsize, i + 2);
							unsigned long long count_com = 0;
							pick_sort_count(a, inputsize, count_com, index);
							cout << count_com << endl;
							
							delete a;
						}
						break;
					case 2:
						// Runtime and comparison
						for (int i = 0; i < 4; i++)
						{
							cout << "--------------------------------" << endl;
							cout << order[i] << endl;
							cout << "Running Time(if required):   ";
							int* a = new int[inputsize];
							int* b = new int[inputsize];
							GenerateData(a, inputsize, i);
							writeFileArray(a, inputsize, i + 2);
							copyArray(a, b, inputsize);
							//Runtime
							start = clock();
							pickSort(a, inputsize, index);
							end = clock();
							double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
							cout << time << " ( ms )" <<endl;
							// Comparison
							cout << "Comparsisions (if required):   ";
							unsigned long long count_com = 0;
							pick_sort_count(a, inputsize, count_com, index);
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
					readSize(inputsize, input);
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

					//
					cout << "AlGORITHM MODE : " << argv[1] << endl;
					cout << "Algorithm : " << argv[2] << endl;
					cout << "input file: " << argv[3] << endl;
					cout << "Input size : " << inputsize << endl;
					cout << "\n-----------------------\n" << endl;
					//


					switch (par)
					{
					case 0:
					{
						// Run time
						cout << "Running time(if required): ";
						int* a = new int[inputsize];
						readFileArray(a, inputsize, input);
						start = clock();
						pickSort(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << "  (ms)" << endl;
						writeFileArray(a, inputsize, 0);
						delete a;
						break;
					}
					case 1:
					{
						//comparison
						cout << "Comparsisions (if required): ";
						int* a = new int[inputsize];
						readFileArray(a, inputsize, input);
						unsigned long long count_com = 0;
						pick_sort_count(a, inputsize, count_com, index);
						cout << count_com << endl;
						writeFileArray(a, inputsize, 0);
						delete a;
						break;
					}
					case 2:
					{
						// Runtime and comparison
						cout << "Running time(if required): ";
						int* a = new int[inputsize];
						int* b = new int[inputsize];
						readFileArray(a, inputsize, input);
						copyArray(a, b, inputsize);
						//Runtime
						start = clock();
						pickSort(a, inputsize, index);
						end = clock();
						double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
						cout << time << "  (ms)" << endl;
						// Comparison
						cout << "Comparsisions (if required): ";
						unsigned long long count_com = 0;
						pick_sort_count(a, inputsize, count_com, index);
						cout << count_com << endl;
						writeFileArray(a, inputsize, 0);
						delete a, b;
						break;
					}
					default:
					{
						break;
					}
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
				readSize(datasize, inputfile);
				cout << " read file success" << endl;
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
					

				//
				cout << "AlGORITHM MODE : " << argv[1] << endl;
				cout << "Algorithm : " << alg1 << "   |    " << alg2 << endl;
				cout << "Input file : " << argv[4] << endl;
				cout << "Input size : " << datasize << endl;
				cout << "\n-----------------------\n" << endl;
				//

				int* a = new int[datasize];
				readFileArray(a, datasize, inputfile);
				int* b = new int[datasize];
				// runtime
				cout << "Running Time:   ";
				//alg1
				copyArray(a, b, datasize);
				start = clock();
				pickSort(b, datasize, index_alg1);
				end = clock();
				double time1 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time1 << "  |   ";
				//alg2
				copyArray(a, b, datasize);
				start = clock();
				pickSort(b, datasize, index_alg2);
				end = clock();
				double time2 = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
				cout << time2 << "  (ms)" << endl;

				// Comparison
				cout << "Comparisons:   ";
				//alg1
				copyArray(a, b, datasize);
				unsigned long long count_com = 0;
				pick_sort_count(b, datasize, count_com, index_alg1);
				cout << count_com << "    |     ";
				// alg2
				copyArray(a, b, datasize);
				count_com = 0;
				pick_sort_count(b, datasize, count_com, index_alg2);
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
					modedata = 3;
				}
				else if (order == "-nsorted")
				{
					modedata = 1;
				}
				else if (order == "-sorted")
				{
					modedata = 0;
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
				{
					cout << "--------error-----" << endl;
					return;
				}
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

				//
				cout << "AlGORITHM MODE : " << argv[1] << endl;
				cout << "Algorithm : " << argv[2] << endl;
				cout << "Input size : " << argv[3] << endl;
				cout << "Input Order : " << argv[4] << endl;
				cout << endl;
				//
				//CMD 2
				switch (par)
				{
				case 0:
				{
					// Run time
					cout << "--------------------------------" << endl;
					cout << order << endl;
					cout << "Running Time(if required):   ";
					int* a = new int[inputsize];
					GenerateData(a, inputsize, modedata);
					writeFileArray(a, inputsize, 1);
					start = clock();
					pickSort(a, inputsize, index);
					end = clock();
					double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
					cout << time << " ( ms )" << endl;
					writeFileArray(a, inputsize, 0);
					delete a;
					break;
				}
				case 1:
				{
					//comparison
					cout << "--------------------------------" << endl;
					cout << order << endl;
					cout << "Comparisions (if required):   ";
					int* a = new int[inputsize];
					GenerateData(a, inputsize, modedata);
					writeFileArray(a, inputsize, 1);
					unsigned long long count_com = 0;
					pick_sort_count(a, inputsize, count_com, index);
					cout << count_com << endl;
					writeFileArray(a, inputsize, 0);
					delete a;

					break;
				}
				case 2:
				{
					// Runtime and comparison
					cout << "--------------------------------" << endl;
					cout << order << endl;
					cout << "Running Time(if required):   ";
					int* a = new int[inputsize];
					int* b = new int[inputsize];
					GenerateData(a, inputsize, modedata);
					writeFileArray(a, inputsize, 1);
					copyArray(a, b, inputsize);
					//Runtime
					start = clock();
					pickSort(b, inputsize, index);
					end = clock();
					double time = ((double(end - start)) * 1000) / CLOCKS_PER_SEC;
					cout << time << " ( ms )" << endl;
					// Comparison
					cout << "Comparisions (if required):   ";
					unsigned long long count_com = 0;
					copyArray(a, b, inputsize);
					pick_sort_count(b, inputsize, count_com, index);
					cout << count_com << endl;
					writeFileArray(b, inputsize, 0);
					delete a, b;
					break;
				}
				default:
					break;
				}
			}
			if (mode == "-c")
			{
				//cmd5
				cout << "Command 5" << endl;

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
					modedata = 3;
				}
				else if (order == "-nsorted")
				{
					modedata = 1;
				}
				else if (order == "-sorted")
				{
					modedata = 0;
				}
				else if (order == "-rev")
				{
					modedata = 2;
				}
				else
				{
					cout << "--------error-----" << endl;
					return;
				}

				//
				cout << "AlGORITHM MODE : " << argv[1] << endl;
				cout << "Algorithm : " << argv[2] << "   |    " << argv[3] << endl;
				cout << "Input size : " << argv[4] << endl;
				cout << "Input Order : " << argv[5] << endl;
				cout << "\n ---------------------------- \n" << endl;

				//

				int* a = new int[datasize];
				GenerateData(a, datasize, modedata);
				writeFileArray(a, datasize, 1);
				int* b = new int[datasize];

				clock_t st1, end1, st2, end2;
				// runtime
				cout << "Running Time:   ";

				//alg1
				copyArray(a, b, datasize);
				st1 = clock();
				pickSort(b, datasize, index_alg1);
				end1 = clock();
				double time1 = ((double(end1 - st1)) * 1000) / CLOCKS_PER_SEC;
				cout << time1 << "  |   ";

				//alg2
				copyArray(a, b, datasize);
				st2 = clock();
				pickSort(b, datasize, index_alg2);
				end2 = clock();
				double time2 = ((double(end2 - st2)) * 1000) / CLOCKS_PER_SEC;
				cout << time2 << "    (ms) " << endl;

				
				// Comparison
				cout << "Comparisons:   ";

				//alg1
				copyArray(a, b, datasize);
				unsigned long long count_com = 0;
				pick_sort_count(b, datasize, count_com, index_alg1);
				cout << count_com << "    |     ";

				// alg2
				copyArray(a, b, datasize);
				count_com = 0;
				pick_sort_count(b, datasize, count_com, index_alg2);
				cout << count_com << endl;
			}
		}

	}

}
