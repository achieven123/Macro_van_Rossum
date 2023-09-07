package deu.mate.api.service;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;

import java.io.IOException;

public class ScheduleService {

    private WebDriver driver;
    private WebElement element;

    // 1. 드라이버 설치 경로
    public static String WEB_DRIVER_ID = "webdriver.chrome.driver";
    public static String WEB_DRIVER_PATH = "C:/chromedriver/chromedriver.exe";
    public static String url = "https://dap.deu.ac.kr/sso/login.aspx";

    public ScheduleService (String id, String pw) {

    }
    public String getSchedule(String id, String pw) {

            try {
                Document doc = Jsoup.connect(url).get();
                Elements elements = doc.getElementsByClass("report_paint_div");

                for (Element element : elements) {
                    System.out.println(element);
                }
            } catch (IOException e) {
                e.printStackTrace();
            }

            return null;
    }
}
