import numpy as np
import matplotlib.pyplot as plt

def plot_graph():
    values = np.loadtxt('simu.txt')
	
    x = values[:,0]
    vendeur = values[:,1]
    achateur = values[:,2]

    V, = plt.plot(x, vendeur, label='Vendeur', color='red')
    A, = plt.plot(x, achateur, label='Acheteur', color='blue')
	
    plt.legend(handles=[V, A])
	
    plt.ylabel('Montant')
    plt.xlabel('temps')

    plt.show()


plot_graph()
