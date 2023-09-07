package deu.mate.api.domain;

import lombok.Builder;
import lombok.Getter;
import lombok.ToString;

@Getter
@Builder
@ToString
public class Notice {

    private String title;
    private String writer;
    private String date;
    private String view;
    private String url;
}
