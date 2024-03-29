#include "core.h"

#include "VaultReader.h"
#include "Note.h"
#include "NoteEmbeddingModel.h"
#include "MongeElkanEmbedding.h"

std::vector<hornbeam::Note> computeEmbeddedNotes(std::vector<std::string> &paths,
                                                 hornbeam::NoteEmbeddingModel &model,
                                                 hornbeam::VaultReader &reader)
{
    std::vector<hornbeam::Note> computed_notes;
    for (const auto &path : paths)
    {
        // TODO(armanbhalla): Optimise by computing the hash of the note text,
        // and retrieving the respective embedding if the text file is a dup-
        // licate of another existing file in the notes directory.
        std::cout << "Processing:" << path << std::endl;
        // TODO(armanbhalla): Apply heavy pre-processing to account for misspellings,
        // perhaps this could include lemmatisation or some other technique. Could also
        // use Named Entity Recognition (NER) and build a topic map that could be used
        // for easy pairwise similarity.
        const std::string noteText = reader.getFileText(path);
        arma::mat computedEmbedding = model.compute(noteText);
        hornbeam::Note new_note(path, noteText, computedEmbedding);
        computed_notes.push_back(new_note);
    }
    return computed_notes;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Hornbeam: Word Embedding Backlink Generator for Personal Knowledge Databases" << std::endl
                  << "Learn more at: https://github.com/techtide/hornbeam" << std::endl
                  << "Usage: ./hornbeam <notes_folder_path>" << std::endl;
        return 1;
    }

    std::string folderPath = argv[1];

    hornbeam::VaultReader vaultReader(folderPath);
    std::vector<std::string> filePaths = vaultReader.getFilePaths();

    hornbeam::MongeElkanEmbedding model;
    std::vector<hornbeam::Note> computedNotes = computeEmbeddedNotes(filePaths, model, vaultReader);

    return 0;
}
