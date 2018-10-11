import com.sun.jna.Library;
import com.sun.jna.Native;
public class JTest {
    // 继承Library，用于加载库文件
    public interface Clibrary extends Library {
        // 加载libhello.so链接库
        Clibrary INSTANTCE = (Clibrary) Native.loadLibrary("test",
                Clibrary.class);

        // 此方法为链接库中的方法
        void test();

        int addTest(int a, int b);
    }

    public static void main(String[] args) {
        // 调用
        Clibrary.INSTANTCE.test();
        int c = Clibrary.INSTANTCE.addTest(10, 20);
        System.out.println(c);
    }
}