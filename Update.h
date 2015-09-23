#ifndef UPDATE_H
#define	UPDATE_H

class Update {
private:
	// 1D Field;
	double *ex;
	double *hy;

	double *ex_now;
	double *ex_bef;

	// 1D psi function
	double *psi_ex;
	double *psi_hy;

	void Alloc1DArray();

	// 3D Field;
	double ***Ex;
	double ***Ey;
	double ***Ez;
	double ***Hx;
	double ***Hy;
	double ***Hz;

	// 3D psi function
	double ***psi_Ex_Hz;
	double ***psi_Ex_Hy;
	double ***psi_Ey_Hx;
	double ***psi_Ey_Hz;
	double ***psi_Ez_Hy;
	double ***psi_Ez_Hx;

	double ***psi_Hx_Ez;
	double ***psi_Hx_Ey;
	double ***psi_Hy_Ex;
	double ***psi_Hy_Ez;
	double ***psi_Hz_Ey;
	double ***psi_Hz_Ex;
	
	void Alloc3DArray();

public:
	Update();
	~Update();

	void Update1Dfield_e(double *Cex, int t);
	void Update1Dfield_h(double *Chy, int t);

	void Update1DCpml_ex();
	void Update1DCpml_hy();

	void Update3Dfield_E(double ***Cexz, double ***Cexy, double ***Ceyx,
						 double ***Ceyz, double ***Cezy, double ***Cezx);
	void Update3Dfield_H(double ***Chxz, double ***Chxy, double ***Chyx,
						 double ***Chyz, double ***Chzy, double ***Chzx);

	void Update3DCpml_E();
	void Update3DCpml_H();

	double *getex();
	double *gethy();

	double ***getEx();
	double ***getEy();
	double ***getEz();
	double ***getHx();
	double ***getHy();
	double ***getHz();
};

#endif