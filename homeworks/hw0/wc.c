#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE * file = fopen(argv[1], "r");
	if (file == NULL) printf ("Error opening file\n");
	else
	{
		int b = 0;
		int l = 0;
		int w = 0;
		char c = 0;
		char c_prev = 0;
		do {
			c = fgetc (file);
			if (c == '\n') l++;
			else if (c != ' ' && c != 0)
			{
				if (c_prev == '\n' || c_prev == ' ') w++;
			}
			c_prev = c;
			b++;
		} while (c != EOF);
		fclose(file);
		b--;
		printf ("%d %d %d %s\n", l, w, b, argv[1]);
	}
	return 0;
}
