import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Monitor{
    private final int MAX = 100;
    private Lock lock = new ReentrantLock();
    private Condition atterraggio = lock.newCondition();
    private Condition decollo = lock.newCondition();
    private Condition servizio = lock.newCondition();
    private int atterraggioSosp, decolloSosp, servizioSosp;
    private int numMezziInPista;
    private boolean pistaOccupataDaAereo;

    public Monitor(){
        this.atterraggioSosp = 0;
        this.decolloSosp = 0;
        this.servizioSosp = 0;
        this.numMezziInPista = 0;
        this.pistaOccupataDaAereo = false;
    }

    public void occupaPista(Mode mode) throws InterruptedException{
        lock.lock();
        try{
            if(mode.equals(Mode.SERVIZIO)){
                while(pistaOccupataDaAereo || atterraggioSosp > 0 || decolloSosp > 0 || numMezziInPista == MAX){
                    servizioSosp++;
                    servizio.await();
                    servizioSosp--;
                }
            }else if(mode.equals(Mode.DECOLLO)){
                while(numMezziInPista > 0 || pistaOccupataDaAereo || atterraggioSosp > 0){
                    decolloSosp++;
                    decollo.await();
                    decolloSosp--;
                }
                pistaOccupataDaAereo = true;
            }else{ //if(mode.equals(Mode.ATTERRAGGIO))
                while(numMezziInPista > 0 || pistaOccupataDaAereo){
                    atterraggioSosp++;
                    atterraggio.await();
                    atterraggioSosp--;
                }
                pistaOccupataDaAereo = true;
            }  
        }finally{
            lock.unlock();
        }
    }
    public void liberaPista(Mode mode) throws InterruptedException{
        lock.lock();
        try{
            if(mode.equals(Mode.ATTERRAGGIO) || mode.equals(Mode.DECOLLO)){
                pistaOccupataDaAereo = false;
            }
    
            if(atterraggioSosp > 0){
                atterraggio.signal();
            }else if(decolloSosp > 0){
                decollo.signal();
            }else{
                servizio.signalAll();
            }
        }finally{
            lock.unlock();
        }
        
    }
}