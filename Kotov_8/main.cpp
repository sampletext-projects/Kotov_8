#include <iostream>
#include <iomanip>

using namespace std;

//вывести веса
void write_mas(double* m, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << setprecision(2) << m[i] << " ";
	}
	cout << "\n";
}

double* randomize(int n)
{
	double* vals = new double[n]{0};
	for (int i = 0; i < n; i++)
	{
		vals[i] = (rand() % 100 - 50) / 10.; // [-5..5]
	}
	return vals;
}

double average(double* m, int size)
{
	double av = 0;
	for (int i = 0; i < size; i++)
	{
		av += m[i];
	}
	av /= size;
	return av;
}

double max_dst_index(double* x, double* y, int size, double c_x, double c_y)
{
	double max_dst = sqrt(pow(x[0] - c_x, 2) + pow(y[0] - c_y, 2));
	int max_index = 0;
	for (int i = 1; i < size; i++)
	{
		double dst = sqrt(pow(x[i] - c_x, 2) + pow(y[i] - c_y, 2));
		if (dst > max_dst)
		{
			max_dst = dst;
			max_index = i;
		}
	}
	return max_index;
}

double* remove_at(double* m, int size, int index)
{
	double* r = new double[size - 1];
	for (int i = 0; i < index; i++)
	{
		r[i] = m[i];
	}

	for (int i = index + 1; i < size; i++)
	{
		r[i - 1] = m[i];
	}
	delete[] m;
	return r;
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Программу сделал Котов.А.А. УМЛ-112\n";
	cout << "Программа для поедания стада овец)\n";

	int sheep;
	cout << "Введите количество овец: ";
	cin >> sheep;

	double* x = randomize(sheep);
	double* y = randomize(sheep);

	write_mas(x, sheep);
	write_mas(y, sheep);

	int eat;
	cout << "Сколько овец хочет съесть волк?: ";
	cin >> eat;

	for (int i = 0; i < eat; i++)
	{
		double avg_x = average(x, sheep);
		double avg_y = average(y, sheep);

		int max_dst = max_dst_index(x, y, sheep, avg_x, avg_y);

		cout << "Волк ест овцу в {" << x[max_dst] << "; " << y[max_dst] << "}\n";

		x = remove_at(x, sheep, max_dst);
		y = remove_at(y, sheep, max_dst);
		sheep--;
	}

	system("pause");

	return 0;
}
