package deu.mate.api.service;

import deu.mate.api.domain.Notice;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.springframework.stereotype.Service;

import javax.annotation.PostConstruct;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@Service
public class NoticeService {
    private static String url = "https://www.deu.ac.kr/www/board/3/1";

    @PostConstruct
    public List<Notice> getNoticeList() throws IOException {
        List<Notice> noticeList = new ArrayList<>();
        Document document = Jsoup.connect(url).get();
        Elements contents = document.select("tbody tr");

        for (Element content : contents) {
            Notice notice = Notice.builder()
                    .title(content.select("td.text-left a").text())
                    .writer(content.select("td:nth-child(3)").text())
                    .date(content.select("td:nth-child(4)"). text())
                    .view(content.select("td:nth-child(5)").text())
                    .url(content.select("td.text-left a").attr("abs:href"))
                    .build();
            noticeList.add(notice);
        }

        return noticeList;
    }
}
