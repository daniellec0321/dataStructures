#include "../include/func.h"

int main()
{
	// initialize structures
	VECTOR<wordle_word> possible_words;
	VECTOR< SET<char> > positions;
	UNOR_MAP< char, unsigned int > req_letters;
	UNOR_MAP< STRING, double > common_scores;

	// create the common scores map
	int is_valid = find_common_score("common-words.txt", common_scores);
	if (is_valid == -1) return EXIT_FAILURE;

	// read in text file
	is_valid = read_file("info-words.txt", common_scores, possible_words);
	if (is_valid == -1) return EXIT_FAILURE;

	// initialize positions vector
	init_pos(positions);

	// tell user to start with the best words
	VECTOR<wordle_word> rec_words = find_words(possible_words, positions, req_letters);
	best_words(rec_words);

	// intializing user input
	STRING user_word;
	COUT << ENDL << "Enter the word you put into wordle (or q to quit): ";
	CIN >> user_word;

	// stores the result of the colors
	STRING result;

	// while loop to keep algorithm running
	while (user_word != "q") {

		COUT << "Enter the color results of that word: ";
		CIN >> result;
		COUT << ENDL;

		// creating temp wordle struct for the user_word
		wordle_word temp_wordle_word(user_word);

		// pruning the structures based on the result
		prune_structures(result, temp_wordle_word, positions, req_letters);

		// finding the potential words
		rec_words = find_words(possible_words, positions, req_letters);

		// finding the highest scoring words
		best_words(rec_words);

		COUT << ENDL << "Enter the word you put into wordle (or q to quit): ";
		CIN >> user_word;

	}

	return 0;
}
