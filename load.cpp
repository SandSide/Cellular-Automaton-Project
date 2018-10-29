void load()
{

	cout << "\nAvailable files to load: \n" << endl;
	// Display txt files vetically
	system("ls | grep .txt | cat");

	// Variable to store user input
	string filename;

	// Ask for user input
	cout << "\nPlease enter file name: " << endl;
	cin >> filename;

	// Add .txt to string to make it easier for opening file
	filename += ".txt";

	// create input file varaible
	ifstream infile;

	// Open file as input
	infile.open(filename, ios::in);

	// if file is open (exists in this case)
	if(infile.is_open() == 1)
	{

		// P0W how-to-detect-empty-file-in-c stackoverflow
		// If file is empty 
		if(infile.peek() == ifstream::traits_type::eof())
		{

			cout << "\nFILE IS EMPTY. " << endl;

		}
		else
		{

			cout << "\nDISPLAYING FILE: " << endl;

			// For every line
			while(!infile.eof())
			{

				// local varaibles
				string line;
				vector<int> vect;

				// get next line in the file
				getline(infile, line);

				// store line in stringstream
				stringstream ss(line);

				unsigned int i;

				// while
				while (ss >> i)
				{

					// push i onto back of string
					vect.push_back(i);

					// if string has ", or " " ignore
					if(ss.peek() == ',' || ss.peek() == ' ')
					{

						ss.ignore();

					}

				}

				// for every 1 and 0 in file display it
				for(i=0; i <vect.size(); i++)
				{

					if(vect.at(i) == 1)
					{

						cout << "\u25A1" << " ";

					}
					else
					{

						cout << "\u25A0" << vect.at(i);

					}

				}

				cout << endl;

			}

		}

	}
	else
	{

		cout << "\nTHE FILE DOES NOT EXIST." << endl;

	}

	// close file
	infile.close();

}



