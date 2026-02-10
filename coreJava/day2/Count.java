package day2;

public class Count {
    String word, sentence;

    Count(String sentence, String word) {
        this.word = word;
        this.sentence = sentence;
    }

    int countSplit() {
        String[] parts = this.sentence.split(this.word, -1);
        return parts.length - 1;
    }

    int countIndexOf() {
        int count = 0;
        int index = 0;

        while ((index = this.sentence.indexOf(this.word, index)) != -1) {
            count++;
            index += this.word.length();
        }
        return count;
    }
}
