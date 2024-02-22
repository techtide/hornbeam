# Hornbeam: Knowledge Base Bootstrapping

Hornbeam is an advanced tool designed to enhance your knowledge management experience within Obsidian or any note-taking system. Leveraging LLM-based word embeddings (BERT) and the Leiden algorithm for hierarchial clustering, Hornbeam intelligently sorts your notes or files into sub-folders using `[[wikilink]]` notation. This effectively assigning each file a 'tag' based on idea similarity. 

The goal is that Hornbeam will help you uncover connections between your ideas and notes, thereby optimising the organisation of your knowledge base. It also helps to mitigate the "cold start" issues often encountered when building out a personal knowledge graph. By utilizing Hornbeam, you can transform your note-taking experience, overcoming the initial challenges of organizing your knowledge base and unlocking new insights through enhanced connectivity and coherence within your personal knowledge graph.

## Key Features:

- **Word Embedding Clustering**: Hornbeam utilizes advanced word embedding techniques to analyze the semantic relationships between your notes, enabling it to cluster them based on idea similarity.

- **Automatic Tagging**: By utilizing `[[wikilink]]` notation commonly found in Obsidian or other note-taking systems, Hornbeam automatically assigns relevant tags to each note, streamlining the organisation process.

- **Optimal Clustering**: The clustering algorithm employed by Hornbeam ensures that notes are grouped together in a manner that maximizes coherence and relevance within each cluster.

- **Enhanced Knowledge Graph**: By effectively organizing your notes into clusters, Hornbeam helps you build a more robust and interconnected knowledge graph, facilitating smoother navigation and exploration of your personal knowledge base.

## How it Works:

1. **Input Files**: Provide Hornbeam with the directory containing your notes or files that you wish to organize.

2. **Semantic Analysis**: Hornbeam employs LLM-based word embeddings to analyze the semantic content of each note, identifying similarities and relationships between ideas.

3. **Clustering**: Based on the semantic analysis, Hornbeam clusters the notes into sub-folders, utilizing `[[wikilink]]` notation to automatically tag each note with relevant keywords or phrases.

4. **Output Optimization**: The resulting folder structure reflects the optimal clustering of notes, enhancing the coherence and accessibility of your knowledge base.

## Getting Started:

1. **Installation**: Clone the Hornbeam repository from GitHub and install the necessary dependencies.

2. **Configuration**: Customize the clustering parameters and file directory settings according to your preferences.

3. **Run Hornbeam**: Execute the Hornbeam script, providing the path to the directory containing your notes as input.

4. **Explore Your Enhanced Knowledge Base**: Navigate through the newly organized folder structure and explore the interconnectedness of your notes within each cluster.

## Example Usage:

You can install the Hornbeam binary for your platform under the 'Releases' tab of GitHub.

```
./hornbeam <path to your notes directory or Obsidian vault>
```

## License:

Hornbeam is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Disclaimer:

Hornbeam is a tool developed independently and is not officially affiliated with Obsidian or any other note-taking platform. It is provided as-is without any guarantees or warranties. Users are encouraged to use it responsibly and ensure the compatibility of their note-taking system with Hornbeam's functionality.
