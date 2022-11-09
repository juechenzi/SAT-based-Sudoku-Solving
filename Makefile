all: sud2sat sat2sud

sud2sat: sud2sat.cpp
	g++ sud2sat.cpp -o sud2sat
sat2sud: sat2sud.cpp
	g++ sat2sud.cpp -o sat2sud

clean:
	rm sud2sat sat2sud
