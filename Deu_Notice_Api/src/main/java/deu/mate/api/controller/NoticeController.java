package deu.mate.api.controller;

import deu.mate.api.domain.Notice;
import deu.mate.api.service.NoticeService;
import deu.mate.api.service.ScheduleService;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import java.io.IOException;
import java.util.List;

@RestController
@RequiredArgsConstructor
public class NoticeController {

    private final NoticeService noticeService;

    @GetMapping("/deu-mate/notice")
    @ResponseBody
    public List<Notice> getNoticeList() throws IOException {
        return noticeService.getNoticeList();
    }

/*
    @GetMapping("/deu-mate/schedule/{id}/{pw}")
    @ResponseBody
    public String getSchedule(@PathVariable String id, @PathVariable String pw) {
        ScheduleService S = new ScheduleService(id, pw);
        return schedule;
    }
*/
}
