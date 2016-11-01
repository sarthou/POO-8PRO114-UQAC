#pragma once

#ifndef PERIODE_H
#define PERIODE_H

class Periode
{
public:
	Periode(int p_duree, int p_but_local = 0, int p_but_adverse = 0);
	~Periode();

	int get_duree() { return m_duree; };
	int get_but_local() { return m_but_local; };
	int get_but_adverse() { return m_but_adverse; };

	void set_duree(int p_duree) { m_duree = p_duree; };
	void set_but_local(int p_nb_but = 0) { m_but_local = p_nb_but; };
	void set_but_adverse(int p_nb_but = 0) { m_but_adverse = p_nb_but; };
	void add_but_local(int p_nb_but = 1) { m_but_local += p_nb_but; };
	void add_but_adverse(int p_nb_but = 1) { m_but_adverse += p_nb_but; };

private:
	int m_duree;
	int m_but_local;
	int m_but_adverse;
};

#endif
